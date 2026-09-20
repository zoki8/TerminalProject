#include "Command.h"
#include "InputProcessor.h"
#include "CommandException.h"
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <cstdio>

using namespace std;

bool InputProcessor::process(string& arg, string& text) {
    text = "";

    if (arg.empty()) {
#ifdef _WIN32
        freopen("CON", "r", stdin);
#endif
        string line;
        while (getline(cin, line))
            text += line + "\n";
        cin.clear();
        clearerr(stdin);

        return true;
    }

    if (arg.size() >= 2 && arg.front() == '"' && arg.back() == '"') {
        text = arg.substr(1, arg.size() - 2);
        arg = "";
        return true;
    }

    ifstream file(arg);
    if (!file)
        throw FileException("Cannot open file: " + arg);

    string line;
    while (getline(file, line))
        text += line + "\n";

    return true;
}