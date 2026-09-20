#pragma once

#include <string>
using namespace std;

class CommandException {
public:
	CommandException(string name, bool isFile,int count, int expected);

	string getMessage();

private:
	string name;
    bool isFile;
	int count;
	int expected;
};