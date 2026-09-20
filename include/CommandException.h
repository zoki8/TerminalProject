#ifndef EXCEPTION
#define EXCEPTION

#include <stdexcept>
#include <string>

class CommandException:public std::runtime_error{
public:
	CommandException(const std::string& msg)
	:std::runtime_error(msg){};
};

class UnknownCommandException:public CommandException{
public:
	UnknownCommandException(const std::string& name)
	:CommandException("Unknown command " + name){};
};

class FileException:public CommandException{
public:
	FileException(const std::string& msg):
	CommandException(msg){};
};

class SyntaxException:public CommandException{
public:
	SyntaxException(const std::string& msg):
	CommandException(msg){};
};
#endif