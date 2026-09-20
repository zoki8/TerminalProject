#ifndef ECHO
#define ECHO
#include "Command.h"
#include <string>
using namespace std;

class EchoCommand:public Command{
public:
    EchoCommand(const string text,bool isfile,bool usingStdin);
    virtual void execute();
    ~EchoCommand();
private:
    string text;
    bool isfile;
    bool usingStdin;
};

#endif