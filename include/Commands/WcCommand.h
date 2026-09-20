#ifndef WC
#define WC
#include "Command.h"
#include <string.h>
#include <iostream>

using namespace std;

class wcCommand: public Command{
public:
    wcCommand( string command, string text,bool isfile,bool usingStdin);
    virtual void execute();
    ~wcCommand();

private:
    int NumberOfWords( string text);
    int NumberOfChars( string text);
    string text;
    string t;
    bool isfile;
    bool usingStdin;
};

#endif