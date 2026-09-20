#include "Reader.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
Reader::Reader(istream* input): input(input){}

string Reader::getLine(){
    string line;
    getline(*input, line);
    return line;
}

bool Reader::isEof() {
    return input->eof();
    
}

ConsoleReader::ConsoleReader()
 : Reader(&cin) {}

