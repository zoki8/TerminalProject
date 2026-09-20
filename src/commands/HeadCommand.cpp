#include "HeadCommand.h"
#include <sstream>
#include "CommandException.h"
#include <vector>

using namespace std;

HeadCommand::HeadCommand(const std::string& opt, const std::string& text)
    : option(opt), text(text), numOfRows(0) {}

void HeadCommand::run() {
    if (option.size() > 7)
        throw SyntaxException("head: invalid option: " + option);

    try {
        numOfRows = stoi(option.substr(2));
    } catch (...) {
        throw SyntaxException("head: invalid line count: " + option.substr(2));
    }

    if (numOfRows < 0)
        throw SyntaxException("head: line count cannot be negative");

    string input = text;
    if (input.empty()) {
        string line;
        while (getline(*in, line))
            input += line + "\n";
    }

    stringstream ss(input);
    string line;
    int count = 0;

    while (count < numOfRows && getline(ss, line)) {
        *out << line << endl;
        count++;
    }
}

