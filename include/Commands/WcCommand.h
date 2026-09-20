#ifndef WCCOMMAND_H
#define WCCOMMAND_H

#include "Command.h"
#include <string>
using namespace std;

class WcCommand : public Command {
private:
    string opt;
    string text;  

public:
    WcCommand(string o, string t);
    void run() override;
};

#endif
