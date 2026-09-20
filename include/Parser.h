#ifndef PARSERH
#define PARSERH
#include "Command.h"
#include <string>
#include <vector>
using namespace std;

class Parser {
public:
	Command* parseCommand(string line);

private:
	vector<string> tokenize(string line);

	Command* parseTime(string cmd,vector<string> tokens);
	Command* parseTouch(string file);
	Command* parseArg(vector<string> tokens,bool opt,string text);
};
#endif