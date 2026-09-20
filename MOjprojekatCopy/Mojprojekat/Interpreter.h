#ifndef INTERPRETERH
#define INTERPRETERH

class Interpreter{
public:
    static Interpreter* getInstance();

    char getSign();
    void setSign(char S,bool temp);
    void reset();
    


private:
    Interpreter();
    static Interpreter* Instance;
    ~Interpreter();

    char Sign;
    bool temp;
    bool temporar;

};

#endif