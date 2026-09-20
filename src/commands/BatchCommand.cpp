#include "BatchCommand.h"
#include "Interpreter.h"
#include "CommandException.h"
#include <fstream>
#include <string>

BatchCommand::BatchCommand(std::string f)
    : filename(f) {}

void BatchCommand::run() {
    if (filename.empty())
        throw SyntaxException("batch: filename not specified");

    std::ifstream file(filename);
    if (!file.is_open())
        throw FileException("batch: cannot open file: " + filename);

    Interpreter* interpreter = Interpreter::getInstance();
    interpreter->setDefaultOut(out);  

    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line.back() == '\r')
            line.pop_back();
        if (line.empty()) continue;
        interpreter->process(line);
    }

    interpreter->setDefaultOut(&std::cout);
}
      // vrati na konzolu