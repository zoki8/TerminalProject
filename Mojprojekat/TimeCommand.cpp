#include "TimeCommand.h"
#include <ctime>
#include <iostream>
using namespace std;
TimeCommand::TimeCommand(){}

void TimeCommand::execute(){

    time_t now =time(0);
    tm* t=std::localtime(&now);
    cout<< (t->tm_hour < 10 ? "0" : "") << t->tm_hour << ":"
        << (t->tm_min < 10 ? "0" : "") << t->tm_min << ":"
        << (t->tm_sec < 10 ? "0" : "") << t->tm_sec
        <<endl;
};