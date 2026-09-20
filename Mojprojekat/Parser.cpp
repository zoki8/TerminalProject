#include "Parser.h"
#include "TimeCommand.h"
#include "DateCommand.h"
#include "TouchCommand.h"
#include "EchoCommand.h"
#include "WcCommand.h"
#include "Command.h"
#include "Interpreter.h"

using namespace std;

//#include "Exceptions.h"

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

Command* Parser::parseCopy(vector<string> tokens){
    return new CopyCommand(tokens[1],tokens[2]);
}

Command* Parser::ParsePrompt(){
    Interpreter::getInstance()->setSign('%',true);
    return nullptr;
}

Command* Parser::parseTime(string cmd,vector<string> tokens) {
    if (tokens.size()==1 || tokens.size()==2) {
        if (cmd == "time"){
            if (tokens.size()==1){
                return new TimeCommand("");
            }else{
                return new TimeCommand(tokens[1]);
            }
        }else{
        return new DateCommand();
        }
    }
    return nullptr;
}

Command* Parser::parseTouch(string filename) {
    return new TouchCommand(filename);
    
}

#include <iostream>

Command* Parser::parseArg(vector<string> tokens,bool opt,string line) {
    int n=tokens.size();
    bool reversing;

    if (opt){
        
        int first = line.find('"');
        if (first != string::npos) {
            int last = line.rfind('"');
            if (last != first){
                int finalLength=min(last, 512);
                finalLength=finalLength-(first+1);
                string text = line.substr(first + 1,finalLength);
                return new wcCommand(tokens[1], text,false,false);
            }
            return new wcCommand(tokens[1], "",false,false);
        }
        if (n==3){
            return new wcCommand(tokens[1],tokens[2],true,false);
        }

        return new wcCommand(tokens[1],"",false,true);
    }else{
        
        if (tokens.size()>1 && tokens[1]=="r"){
            reversing=true;
            if (reversing){
                
            }
            int first = line.find('"');
            if (first != string::npos) {
                int last = line.rfind('"');
                if (last != first){
                    int finalLength=min(last, 512);
                    finalLength=finalLength-(first+1);
                    string text = line.substr(first + 1, finalLength);
                    return new EchoCommand(text,false,false,reversing);
            }
            
            return new EchoCommand("",false,false,reversing);
            }
            if (n==3){
                return new EchoCommand(tokens[2],true,false,reversing);
            }

            return new EchoCommand("",false,true,reversing);
        }else{
            
            reversing=false;
            
            int first = line.find('"');
            if (first != string::npos) {
                int last = line.rfind('"');
                if (last != first){
                    int finalLength=min(last, 512);
                    finalLength=finalLength-(first+1);
                    string text = line.substr(first + 1, finalLength);
                    return new EchoCommand(text,false,false,reversing);
            }
            
            return new EchoCommand("",false,false,reversing);
            }
            if (n==2){
                return new EchoCommand(tokens[1],true,false,reversing);
            }

            return new EchoCommand("",false,true,reversing);

        }
    
    }
}