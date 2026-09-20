#ifndef PROMPTH
#define PROMPTH
#include <iostream>
#include "Command.h"
#include "Interpreter.h"
#include <string>

class PromptCommand:public Command{

public:
    PromptCommand(const std::string& t);
    void run() override;
private:
    std::string text;
};

#endif