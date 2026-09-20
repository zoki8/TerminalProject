#include "trCommand.h"
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "LineParser.h"
#include "CommandException.h"

using namespace std;

TrCommand::TrCommand(const std::string& options, const std::string& filename, const std::string& text)
    : options(options), text(text), filename(filename) {}

void TrCommand::run() {
    string input = text;
    if (input.empty()) {
        string line;
        while (getline(*in, line))
            input += line + "\n";
    }

    vector<string> optionList = LineParser::tokenize(options);

    if (optionList.empty())
        throw SyntaxException("tr: no options specified");

    string what = optionList[0].substr(2, optionList[0].size() - 3);
    string with = "";

    if (what.empty())
        throw SyntaxException("tr: search string cannot be empty");

    if (optionList.size() > 1)
        with = optionList[1].substr(1, optionList[1].size() - 2);

    size_t pos = 0;
    while ((pos = input.find(what, pos)) != string::npos) {
        input.replace(pos, what.size(), with);
        pos += with.size();
    }

    /*if (!filename.empty()) {
        ofstream file(filename, ios::trunc);
        if (!file)
            throw FileException("tr: cannot open file: " + filename);
        file << input << endl;
        return;
    }*/

    *out << input << endl;
}