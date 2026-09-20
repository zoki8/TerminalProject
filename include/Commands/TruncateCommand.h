#ifndef TRUNCATECOMMAND_H
#define TRUNCATECOMMAND_H

#include "Command.h"
#include <string>

using namespace std;

class TruncateCommand : public Command {
private:
    string filename;

public:
    TruncateCommand(string f);
    void run() override;
};

#endif
