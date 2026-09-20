#include "EchoCommand.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

EchoCommand::EchoCommand(string text,bool isfile,bool usingStdin): text(text),isfile(isfile),usingStdin(usingStdin){};

void EchoCommand::execute(){
    if (isfile) {
        text=readFile(text);
    }else if(usingStdin){
        text=readfromStdin();
    }else{
        text=text;
    }

    cout<<text<<endl;   
}

EchoCommand::~EchoCommand() {}


