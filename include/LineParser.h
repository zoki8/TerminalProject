#ifndef LINEPARSER_H
#define LINEPARSER_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LineParser{
private:
    string name,opt,arg;
public:
    bool parse(const string line);

    static string joinStrings(const vector<string>& tokens, size_t start);

    static vector<string> tokenize(string line);

    string getName() const;
    string getOpt() const;
    string getArg() const;
};

#endif

