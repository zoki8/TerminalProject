#include "Interpreter.h"
#include "Parser.h"
#include "TimeCommand.h"
#include "DateCommand.h"
#include "TouchCommand.h"
#include "EchoCommand.h"
#include "WcCommand.h"
#include "Command.h"
#include "Interpreter.h"

using namespace std;

Interpreter* Interpreter::Instance = nullptr;

Interpreter::Interpreter(): Sign('$'){};

Interpreter* Interpreter::getInstance(){
    if (Instance == nullptr){
        Instance = new Interpreter;
    }
    return Instance;
}
Interpreter::~Interpreter(){};

char Interpreter::getSign(){
    return Sign;
}

void Interpreter::setSign(char S,bool temp){
    Sign=S;
    temporar=temp;
}

void Interpreter::reset(){
    if(temporar){
        Sign='$';
        temporar=false;
    }
}

Command* Parser::parseCommand(string line) {
    vector<string> tokens = tokenize(line);

    if (tokens.empty())
        return nullptr;

    string cmd = tokens[0];
    int n = tokens.size();

    if (cmd == "last") {
        cout<<lastLine<<endl;
        return parseCommand(lastLine);
    }else{
        lastLine=line;
    }
    if (cmd == "prompt" && tokens[1]=="-x") {
        return ParsePrompt();
    }

    if (cmd == "touch" && n==2) {
        return parseTouch(tokens[1]);
    }

    if (cmd == "echo" && n>=1) {
        return parseArg(tokens,false,line);
    }

    if ((cmd == "time" || cmd=="date")) {
        return parseTime(cmd,tokens);
    }

    if (cmd == "wc" && n>=2) {
        return parseArg(tokens,true,line);
    }
    if (cmd == "copy" && n>=3) {
        return parseCopy(tokens);
    }


    return nullptr;
}

vector<string> Parser::tokenize(string line) {
    vector<string> tokens;
    string current;

    for (char c : line) {
        if (isspace(c)) {
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        }
        else {
            current.push_back(c);
        }
    }

    if (!current.empty()) {
        tokens.push_back(current);
    }

    return tokens;
}