#ifndef INTERPRETERH
#define INTERPRETERH

class Interpreter{
public:
    static Interpreter* getInstance();

    char getSign();
    void setSign(char S);
    


private:
    Interpreter();
    static Interpreter* Instance;
    ~Interpreter();

    char Sign;

};

#endif