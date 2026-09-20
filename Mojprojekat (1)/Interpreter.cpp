#include "Interpreter.h"
Interpreter* Interpreter::Instance = nullptr;

Interpreter::Interpreter(): Sign('$'){};

Interpreter* Interpreter::getInstance(){
    if (Instance == nullptr){
        Instance = new Interpreter;
    }
    return Instance;
}
Interpreter::~Interpreter(){};

char Interpreter::getSign(){
    return Sign;
}

void Interpreter::setSign(char S){
    Sign=S;
}