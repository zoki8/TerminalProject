#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H

#include <string>

class Command;

class CommandFactory {
public:
    // Pravi odgovaraju?u komandu na osnovu imena
    static Command* create(const std::string& name,
        const std::string& opt,
        const std::string& text,
        const std::string& arg);
};

#endif
