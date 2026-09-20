#include "TimeCommand.h"
#include <ctime>
#include <iostream>
#include "CommandException.h"
#include "string"
#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
TimeCommand::TimeCommand(){}

void TimeCommand::run(){

    time_t now =time(0);
    tm* t=std::localtime(&now);

    if (!t)
        throw CommandException("time: failed to get local time.");

    *out<< (t->tm_hour < 10 ? "0" : "") << t->tm_hour << ":"
        << (t->tm_min < 10 ? "0" : "") << t->tm_min << ":"
        << (t->tm_sec < 10 ? "0" : "") << t->tm_sec
        <<endl;
};

/* 
#include "TimeCommand.h"


#include <ctime>
#include <iostream>
#include "CommandException.h"
#include "string"

using namespace std;
TimeCommand::TimeCommand(){}

void TimeCommand::run(){

    time_t now = time(0);
    tm t;
    localtime_s(&t, &now);

    *out << (t.tm_hour < 10 ? "0" : "") << t.tm_hour << ":"
         << (t.tm_min < 10 ? "0" : "") << t.tm_min << ":"
         << (t.tm_sec < 10 ? "0" : "") << t.tm_sec
         << endl;
};
*/