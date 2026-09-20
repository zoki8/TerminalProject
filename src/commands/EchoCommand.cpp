#include "EchoCommand.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "CommandException.h"

using namespace std;

EchoCommand::EchoCommand(string t)
    : text(t) {
}

void EchoCommand::run() {
    string input = text;
    if (input.empty()) {
        string line;
        if (getline(*in, line)){
            input += line;
            while (getline(*in, line))
                input += "\n" + line;
        } 
    }
    *out << input;
    if (out == &cout)
        *out << "\n";
}

