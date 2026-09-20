#include "TimeCommand.h"
#include <ctime>
#include <iostream>
using namespace std;
TimeCommand::TimeCommand(string opt):opt(opt){}
void TimeCommand::execute(){

    time_t now =time(0);
    tm* t=std::localtime(&now);
    if (opt=="-h"){
        cout<< (t->tm_hour < 10 ? "0" : "") << t->tm_hour <<endl;
    }else if (opt=="-m"){
        cout<< (t->tm_min < 10 ? "0" : "") << t->tm_min <<endl;

    }else if (opt=="-s"){
        cout<< (t->tm_sec < 10 ? "0" : "") << t->tm_sec<<endl;
    }else{
        cout<< (t->tm_hour < 10 ? "0" : "") << t->tm_hour << ":"
            << (t->tm_min < 10 ? "0" : "") << t->tm_min << ":"
            << (t->tm_sec < 10 ? "0" : "") << t->tm_sec
            <<endl;
    }
};