#include "TouchCommand.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Exceptions.h"

using namespace std;

TouchCommand::TouchCommand(string filename)
    : filename(filename) {}

void TouchCommand::execute() {
    ifstream file(filename);

    if (file.good()) {
        throw new CommandException(filename,true,0,0);
    }
    ofstream out(filename);

    if (!out) {
        cout << "Can not make a file." << endl;
        return;
    }
}