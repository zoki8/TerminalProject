#ifndef TOUCH
#define TOUCH
#include "Command.h"
#include <string>
using namespace std;

class TouchCommand:public Command{
public:
    TouchCommand(string filename);
    virtual void execute();
private:
    string filename;
};

#endif