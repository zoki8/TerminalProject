#ifndef READERH
#define READERH
#include <string>
#include <istream>
#include <ostream>
using namespace std;


class Reader{
public:
    Reader(istream* input);

    string getLine();
    bool isEof();
    ~Reader()=default;


protected:
    istream* input;
};

class ConsoleReader : public Reader {
public:
	ConsoleReader();
};




#endif