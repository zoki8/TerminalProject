#include "Command.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

string Command::readFile(string filename){
    ifstream file(filename);
    string text;
    char c;

    if (!file.is_open()){
        return "";
    }

    while (text.length()<512 && file.get(c)){
        text.push_back(c);
    }
    return text;
}

string Command::readfromStdin() {
    string text, line;

    while (getline(cin, line)) {
        text += line;
        text += '\n';
    }
    if (text.length()>512){
        text=text.substr(0,512);
    }

    cin.clear();  
    clearerr(stdin);
    return text;
}

string Command::reverseString(string text) {
    string reversed;
    char c;
    for (int i=text.length()-1;i>=0;i--){
        reversed+=text[i];
    }
    return reversed;
}