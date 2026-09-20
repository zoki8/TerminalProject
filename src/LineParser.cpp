#include "LineParser.h"
#include <sstream>
#include <vector>
#include <string>

string LineParser::joinStrings(const vector<string>& tokens,size_t start){
    string result;
    for(size_t i=start;i<tokens.size();i++){
        if (i>start) result+=" ";
        result+=tokens[i];
    }
    return result;
}

vector<string>  LineParser::tokenize(string line){
    vector<string> tokens;
    string current="";
    bool inQuote=false;

    for (char c: line){
        if (c=='"'){
            inQuote=!inQuote;
            current.push_back(c);
        }else if(isspace((unsigned char)c) && !inQuote){
            if (!current.empty()) {
                tokens.push_back(current);
                current.clear();
            }
        }else{
            current.push_back(c);
        }
    }
    if (!current.empty()){
        tokens.push_back(current);
    }
    return tokens;
};

bool LineParser::parse(string line){
    name=opt=arg="";
    vector<string> tokens=tokenize(line);
    int size=tokens.size();

    if (size>=1){
        name=tokens[0];
    }else{
        return false;
    };
    
    if (size<2) return true;
    
    if(name=="tr"){
        if (tokens[1][0]=='-'){
            arg="";
            opt=joinStrings(tokens,1);
        }
        else{
            arg=tokens[1];
            opt=joinStrings(tokens,2);
        }
    }else if (tokens[1].size()>1 && tokens[1][0]=='-'){
            opt=tokens[1];
            arg=joinStrings(tokens,2);
    }
    else {
        arg=joinStrings(tokens,1);
    }

    while (!arg.empty() && (arg[0] == ' ' || arg[0]=='\t')){
        arg.erase(0,1);
    }
    return true;
}

string LineParser::getName() const {return name;}
string LineParser::getOpt() const {return opt;}
string LineParser::getArg() const {return arg;}
