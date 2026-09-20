#include "EchoCommand.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

EchoCommand::EchoCommand(string text,bool isfile,bool usingStdin,bool isReverse): text(text),isfile(isfile),usingStdin(usingStdin), isReverse(isReverse){};

void EchoCommand::execute(){
    
    if (isfile) {
        text=readFile(text);
    }else if(usingStdin){
        text=readfromStdin();
    }else{
        text=text;
    }
    if (isReverse) text=reverseString(text);
    cout<<text<<endl;   
}

EchoCommand::~EchoCommand() {}


CopyCommand::CopyCommand(string inFile,string outFile):inFile(inFile),outFile(outFile){

}

void CopyCommand::execute(){
    ifstream in(inFile);
    
    ofstream out(outFile);
    out<<in.rdbuf();

    in.close();
    out.close();

}