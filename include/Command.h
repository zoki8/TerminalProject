#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>

class Command {
public:
    Command():in(&std::cin),out(&std::cout){};

    virtual void run() = 0;
    virtual ~Command() {}

    void setIn(std::istream* i ){
        in=i;
    }

    void setOut(std::ostream* o){
        out=o;
    }; 

protected:
    std::istream* in;
    std::ostream* out;

};

#endif
