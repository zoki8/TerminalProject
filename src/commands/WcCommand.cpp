#include "WcCommand.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <cstdio>

wcCommand::wcCommand(string t, string text,bool isfile,bool usingStdin)
    : text(text), t(t),isfile(isfile), usingStdin(usingStdin){}

int wcCommand::NumberOfChars(string text){
   
    int count=0;

    for (char c:text){
        if (!isspace(c)){
            count++;
        }
    }
    return count;
}

int wcCommand::NumberOfWords(string text){
   
    int count=0;
    bool IsIn=false;

    for (char c:text){
        if (isspace(c)){
            IsIn=false;
        }else{
            if(!IsIn){
                count++;
                IsIn=true;
            }
        }
    }
    return count;
}

void wcCommand::execute(){

    if (isfile) {
        text=readFile(text);
    }else if(usingStdin){
        text=readfromStdin();
    }else{
        text=text;
    }

    if (t=="-c"){
        cout << NumberOfChars(text) << endl;
    }
    if (t=="-w"){
        cout << NumberOfWords(text) << endl;
        };
    
}

wcCommand::~wcCommand() {}