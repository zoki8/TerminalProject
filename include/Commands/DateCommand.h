#ifndef DATE
#define DATE
#include "Command.h"

class DateCommand:public Command{
public:
    virtual void execute();
};

#endif