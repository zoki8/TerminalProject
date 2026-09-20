#include "Exceptions.h"
#include <sstream>
using namespace std;

CommandException::CommandException(string name,bool isFile, int count, int expected)
 : name(name),isFile(isFile), count(count), expected(expected) {}
 

string CommandException::getMessage() {
    if (!isFile){
        stringstream ss;
        ss << "Komanda " << name << " ocekuje " << expected
            << " argumenata, a dobila je " << count;
        return ss.str();

    }else{
        stringstream ss;
        ss << "File " << name << " already exists";
        return ss.str();

    }
	
}
