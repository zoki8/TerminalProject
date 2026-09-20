#ifndef COMMANDSH
#define COMMANDSH
#include <string>
#include <iostream>
using namespace std;

class Command{
public:
    virtual string readFile(string filename);
    virtual void execute()=0;
    virtual ~Command() {};
    virtual string readfromStdin();
    virtual string reverseString(string text);

private:
    string filename;
    string text;

};

#endif