#include "rmCommand.h"
#include <fstream>
#include <filesystem>
#include "CommandException.h"
#include "string"

using namespace std;

rmCommand::rmCommand(string f)
    : filename(f) {
}

void rmCommand::run() {

    if (filename.empty())
        throw SyntaxException("rm: filename not specified.");

    ifstream check(filename);
    if (!check) 
        throw FileException("rm: file does not exist " + filename);

    try {std::filesystem::remove(filename);
    } catch(...) {
        throw FileException("rm: cannot delete file " + filename);
    }
}
