#include <iostream>
#include <string>
using namespace std;
#include "Interpreter.h"
#include "Reader.h"
#include "Command.h"
#include "Parser.h"
#include "Exceptions.h"

int main(){
    string line;

    Interpreter* Inter = Interpreter::getInstance();
    Reader* Read = new ConsoleReader();
    Parser* parser = new Parser();

    while (true) {
            

            cout<<Inter->getSign()<<" ";
            Inter->reset();

                try{
                    line = Read->getLine();

                    if (Read->isEof()) {
                        cin.clear();
                        clearerr(stdin); 
                        cout << endl;    
                        continue;        
                    }

                    if (line.empty()) continue;
                    
                    Command* cmd = parser->parseCommand(line);       
                    if (cmd){
                        cmd->execute();
                        delete cmd;
                    } 
                }
                catch(CommandException* e){
                    cout << e->getMessage()<< '\n';
                    delete e;
                }
                
                
    }	
    
    return 0;
}