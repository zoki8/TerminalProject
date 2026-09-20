#ifndef HEADCOMMANDH
#define HEADCOMMANDH
#include "Command.h"
#include <iostream>
#include <string>

class HeadCommand:public Command{
public:
    HeadCommand(const std::string& opt,const std::string& text);
    void run() override;
private:
    int numOfRows;
    std::string option;
    std::string text;
};


#endif