#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Command.h"

class Interpreter {
public:
    static Interpreter* getInstance();
    std::string getSign();
    void setSign(const std::string& S);
    void setSign(char c);
    void process(std::string line);
    std::ostream* defaultOut = &std::cout; 
    void setDefaultOut(std::ostream* o) { defaultOut = o; }
    ~Interpreter();

private:
    Interpreter();
    static Interpreter* Instance;
    Interpreter(const Interpreter&) = delete;
    Interpreter& operator=(const Interpreter&) = delete;
    std::string Sign;

    std::vector<std::string> splitPipe(const std::string& line);
    Command* buildCommand(const std::string& segment, std::string& text, bool fromPipe, std::ostream*& outStream);
    Command* buildCommand(const std::string& segment, std::string& text, bool fromPipe = false);
};

#endif