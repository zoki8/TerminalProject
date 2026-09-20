#ifndef RMCOMMAND_H
#define RMCOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class rmCommand : public Command {
private:
    string filename;

public:
    rmCommand(string f);
    void run() override;
};

#endif
