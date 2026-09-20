#ifndef TRCOMMANDH
#define TRCOMMANDH
#include "Command.h"
#include <string>
#include <iostream>

class TrCommand:public Command{
public:
    TrCommand(const std::string& options,const std::string& filename, const std::string& text);
    void run() override;
private:
    std::string options;
    std::string text;
    std::string filename;
};

#endif