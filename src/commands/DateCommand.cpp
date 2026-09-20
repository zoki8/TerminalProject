#include "DateCommand.h"
#include <ctime>
#include <iostream>
#include "CommandException.h"
#include "string"
using namespace std;

void DateCommand::run(){

    time_t now =time(0);
    tm* t=std::localtime(&now);

    if (!t) 
        throw CommandException("date: failed to get local time.");

    *out<< t->tm_mday << "."
        << t->tm_mon +1<< "."
        << t->tm_year+1900<<"."
        <<endl;

};
/*
#include "DateCommand.h"
#include <ctime>
#include <iostream>
#include "CommandException.h"
#include "string"
using namespace std;

void DateCommand::run(){

    time_t now = time(0);
    tm t;
    localtime_s(&t, &now);

    *out << t.tm_mday << "."
         << t.tm_mon + 1 << "."
         << t.tm_year + 1900 << "."
         << endl;
};
*/