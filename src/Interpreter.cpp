#include "Interpreter.h"
#include "LineParser.h"
#include "Command.h"
#include "InputProcessor.h"
#include "CommandFactory.h"
#include "CommandException.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <iostream>
#include <filesystem>

using namespace std;

Interpreter* Interpreter::Instance = nullptr;

Interpreter::Interpreter() : Sign("$") {}
Interpreter::~Interpreter() {}

Interpreter* Interpreter::getInstance() {
    if (Instance == nullptr)
        Instance = new Interpreter;
    return Instance;
}

string Interpreter::getSign() {
    return Sign;
}

void Interpreter::setSign(const string& P) {
    Sign = P;
}

void Interpreter::setSign(char P) {
    Sign = string(1, P);
}

vector<string> Interpreter::splitPipe(const string& line) {
    vector<string> segments;
    string current;
    bool inQuote = false;

    for (char c : line) {
        if (c == '"') {
            inQuote = !inQuote;
            current.push_back(c);
        } else if (c == '|' && !inQuote) {
            size_t start = current.find_first_not_of(" \t");
            size_t end   = current.find_last_not_of(" \t");
            if (start != string::npos)
                segments.push_back(current.substr(start, end - start + 1));
            else
                segments.push_back("");
            current.clear();

        } else {
            current.push_back(c);
        }
    }

    size_t start = current.find_first_not_of(" \t");
    size_t end   = current.find_last_not_of(" \t");
    if (start != string::npos)
        segments.push_back(current.substr(start, end - start + 1));
    else
        segments.push_back("");

    return segments;
}

Command* Interpreter::buildCommand(const string& segment, string& text, bool fromPipe, ostream*& outStream) {
    string cleanSegment = segment;
    string outFile = "";
    string inFile  = "";
    bool append = false;

    auto trim = [](const string& s) -> string {
        size_t st = s.find_first_not_of(" \t");
        size_t en = s.find_last_not_of(" \t");
        return (st != string::npos) ? s.substr(st, en - st + 1) : "";
    };

    auto findOutsideQuotes = [](const string& s, const string& igla) -> size_t {
        bool inQ = false;
        for (size_t i = 0; i + igla.size() <= s.size(); i++) {
            if (s[i] == '"') { inQ = !inQ; continue; }
            if (!inQ && s.substr(i, igla.size()) == igla)
                return i;
        }
        return string::npos;
    };

    size_t posAppend = findOutsideQuotes(cleanSegment, ">>");
    size_t posOut = findOutsideQuotes(cleanSegment, ">");

    if (posAppend != string::npos) {
        append = true;
        outFile = trim(cleanSegment.substr(posAppend + 2));
        cleanSegment = cleanSegment.substr(0, posAppend);
    } else if (posOut != string::npos) {
        outFile = trim(cleanSegment.substr(posOut + 1));
        cleanSegment = cleanSegment.substr(0, posOut);
    }

    size_t posIn = findOutsideQuotes(cleanSegment, "<");
    if (posIn != string::npos) {
        inFile = trim(cleanSegment.substr(posIn + 1));
        cleanSegment = cleanSegment.substr(0, posIn);
    }

    cleanSegment = trim(cleanSegment);

    LineParser parser;

    if (!parser.parse(cleanSegment))
        throw SyntaxException("Cannot parse: " + cleanSegment);

    string name = parser.getName();
    string opt = parser.getOpt();
    string arg = parser.getArg();

    if (fromPipe && (name == "date" || name == "time"))
        throw SyntaxException(name + ": cannot be used after pipe");

    bool needsInput = (name == "echo" || name == "wc" || name == "tr" || name == "head");

    if (needsInput && !fromPipe) {
        if (!inFile.empty()) {
            if (!arg.empty())
                throw SyntaxException(name + ": cannot use both argument and input redirection");
            arg = inFile;
        }
        InputProcessor input;
        input.process(arg, text);
    } else if (!inFile.empty() && fromPipe) {
        throw SyntaxException(name + ": cannot redirect input of piped command");
    }

    Command* cmd = CommandFactory::create(name, opt, text, arg);
    
    if (!cmd)
        throw UnknownCommandException(name);

    if (!outFile.empty()) {
        auto mode = append ? (ios::out | ios::app) : (ios::out | ios::trunc);
        if (append) {
            ifstream check(outFile, ios::binary | ios::ate);
            if (check.is_open() && check.tellg() > 0) {
                check.seekg(-1, ios::end);
                char c; check.get(c);
                check.close();
                if (c == '\n')
                    filesystem::resize_file(outFile, filesystem::file_size(outFile) - 1);
            }
        }
        ofstream* fileOut = new ofstream(outFile, mode);
        if (!fileOut->is_open()) {
            delete fileOut;
            delete cmd;
            throw FileException("Cannot open output file: " + outFile);
        }
        outStream = fileOut;
        cmd->setOut(fileOut);
    }else {
        cmd->setOut(defaultOut);
    }
    return cmd;
}
Command* Interpreter::buildCommand(const string& segment, string& text, bool fromPipe) {
    ostream* dummy = nullptr;
    return buildCommand(segment, text, fromPipe, dummy);
}

void Interpreter::process(string line) {
    line = line.substr(0, 512);

    try {
        vector<string> segments = splitPipe(line);

        if (segments.size() == 1 && segments[0].empty())
            return;

        for (const auto& s : segments) {
            if (s.empty())
                throw SyntaxException("invalid pipe syntax");
        }
        
        vector<Command*> commands;
        vector<stringstream*> pipeStreams;
        vector<ostream*> fileStreams;

        for (size_t i = 0; i < segments.size(); i++) {
            string text = "";
            ostream* outStream = nullptr;
            if (i < segments.size() - 1 && segments[i].find('>') != string::npos) {
                throw SyntaxException("cannot redirect output of piped command");
            }

            Command* cmd = buildCommand(segments[i], text, i > 0, outStream);

            commands.push_back(cmd);
            pipeStreams.push_back(new stringstream());

           /* if (i < segments.size() - 1)
                pipeStreams.push_back(new stringstream());
            else
                pipeStreams.push_back(nullptr);*/

            if (outStream)
                fileStreams.push_back(outStream);

            /*if (i > 0 && pipeStreams[i - 1])
                cmd->setIn(pipeStreams[i - 1]);
                */
            if (i > 0)
                cmd->setIn(pipeStreams[i - 1]);
            if (i < segments.size() - 1 && outStream == nullptr)
                cmd->setOut(pipeStreams[i]);
        }
        
        
        for (Command* cmd : commands){
            cmd->run();
        }

        for (ostream* fs : fileStreams) {
            fs->flush();
        }
        
        for (Command* cmd : commands)    delete cmd;
        for (stringstream* ss : pipeStreams) delete ss;
        for (ostream* fs : fileStreams)  delete fs;

    } catch (const CommandException& e) {
        cout << flush;
        cerr << e.what() << endl;
    }
}