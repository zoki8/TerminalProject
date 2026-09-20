#ifndef TIME
#define TIME
#include "Command.h"
#include <string>
#include <iostream>
using namespace std;

class TimeCommand:public Command{
public:
    TimeCommand();
    virtual void execute();
};

#endif