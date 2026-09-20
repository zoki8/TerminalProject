#include "WcCommand.h"
#include <iostream>
#include <string>
#include <cctype>
#include "CommandException.h"

using namespace std;

WcCommand::WcCommand(string o, string t)
    : opt(o), text(t) {
}

void WcCommand::run() {

    string input = text;
    if (input.empty()) {
        string line;
        while (getline(*in, line))
            input += line;
    }

    if (opt == "-c") { 
        int count=input.size();
        *out << count <<endl; 
        *out << flush;
        return; 
    }

    if (opt != "-w") { 
        throw SyntaxException("wc: unsupported option " + opt);
    }

    int cnt = 0;
    bool inWord = false;
    for (size_t i = 0; i < input.size(); i++) {
        char c = input[i];
        if (isspace(c)) inWord = false;
        else if (!inWord) { cnt++; inWord = true; }
    }
    *out << cnt <<endl;

    
}
