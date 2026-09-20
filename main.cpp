#include <iostream>
#include "Interpreter.h"

int main() {
    Interpreter* Inter=Interpreter::getInstance();
    bool isOn=true;

    while (true) {

        if (isOn){
            std::cout <<Inter->getSign();
            isOn=true;
        }
        
        std::string line;

        if (!std::getline(std::cin, line)){
            if (std::cin.eof()){
                isOn=!isOn;
                std::clearerr(stdin);
                std::cin.clear();
                continue;
            }
            break;
        } 

        if (line.empty()) continue;         

        Inter->process(line);
    }

    return 0;
}
