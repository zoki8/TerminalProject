#include "TruncateCommand.h"
#include <fstream>
#include <iostream>
#include "CommandException.h"
#include "string"

using namespace std;

TruncateCommand::TruncateCommand(string f)
    : filename(f) {
}

void TruncateCommand::run() {

    if (filename.empty()) {
        throw SyntaxException("truncate: filename not specified.");
    }

    ifstream check(filename);
    if (!check) {
        throw FileException("truncate: file does not exists " + filename);
    }

    std::ofstream file(filename,std::ios::trunc);

    if (!file)
        throw FileException("truncate: cannot open file " + filename);
}
