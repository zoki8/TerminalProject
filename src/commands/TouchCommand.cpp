#include "TouchCommand.h"
#include <fstream>
#include "CommandException.h"
#include "string"

using namespace std;

TouchCommand::TouchCommand(string f)
    : filename(f) {
}

void TouchCommand::run() {

    if (filename.empty()) 
        throw SyntaxException("touch: filename not specified.");

    ifstream check(filename);
    if (check) 
        throw FileException("touch: file already exists " + filename );
    
    ofstream file(filename);
    if (!file)
        throw FileException("touch: cannot open file " + filename);
}
