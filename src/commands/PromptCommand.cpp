#include "PromptCommand.h"
#include <iostream>
#include "Interpreter.h"
#include <string>
#include "CommandException.h"

PromptCommand::PromptCommand(const std::string& text): text(text){}

void PromptCommand::run() {
    if (text.size() >= 2 && text.front() == '"' && text.back() == '"')
        Interpreter::getInstance()->setSign(text.substr(1, text.size() - 2));
    else{
        throw SyntaxException("Syntax error");
    }
        
}