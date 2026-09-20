#include "DateCommand.h"
#include <ctime>
#include <iostream>
using namespace std;

void DateCommand::execute(){

    time_t now =time(0);
    tm* t=std::localtime(&now);
    cout<< t->tm_mday << "."
        << t->tm_mon +1<< "."
        << t->tm_year+1900<<"."
        <<endl;

};
