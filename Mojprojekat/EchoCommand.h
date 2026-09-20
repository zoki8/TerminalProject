#ifndef ECHO
#define ECHO
#include "Command.h"
#include <string>
using namespace std;

class EchoCommand:public Command{
public:
    EchoCommand(const string text,bool isfile,bool usingStdin,bool isReverse);
    virtual void execute();
    ~EchoCommand();
private:
    string text;
    bool isfile;
    bool usingStdin;
    bool isReverse;
};

#endif

class CopyCommand:public Command{
public:
    CopyCommand(string inFile,string outFile);
    virtual void execute();

private:
    string inFile,outFile;

};