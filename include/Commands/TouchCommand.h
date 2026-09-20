#ifndef TOUCHCOMMAND_H
#define TOUCHCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class TouchCommand : public Command {
private:
    string filename;

public:
    TouchCommand(string f);
    void run() override;
};

#endif
