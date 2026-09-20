#ifndef BATCH
#define BATCH
#include <iostream>
#include <string>
#include "Command.h"



class BatchCommand:public Command{

private:
    std::string filename;
public:
    BatchCommand(std::string f);
    void run();
};

#endif