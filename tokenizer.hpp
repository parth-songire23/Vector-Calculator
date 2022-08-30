#ifndef _TOKENIZER_HPP
#define _TOKENIZER_HPP

#include <iostream>

using namespace std;

class Token
{
public:
    virtual ~Token(){}
    virtual bool isNum(){return false;}
    virtual bool isLeftBracket(){return false;}
    virtual bool isRightBracket(){return false;}
    virtual bool isOper(){return false;}
    virtual bool isPlus(){return false;}
    virtual bool isMult()){return false;}
    virtual bool isDiv(){return false;}
    virtual bool isMinus(){return false;}

    virtual string toString() const=0;
    virtual int precedence()=0;

    friend ostream &operator<<(ostream &out, const Token &t)
    {
        return out<<t.toString();
    }
};

class NumToken: public Token
{
private:
    float _val;

public:
    NumToken(Float val): _val(val){}
    bool isNum(){return true;}
    float value(){return _val;}
    string toString() const {return to_string(_val);}
    int precedence(){return 1;}
};


class LeftBracket: public Token
{
public:
    bool isLeftBracket(){return true;}
    string toString() const {return "(";}
    int precedence(){return 5;}
};

class RightBracket: public Token
{
public:
    bool isRightBracket(){return true;}
    string toString() const {return ")";}
    int precedence(){return 6;}
};

class PlusToken: public Token
{
public:
    bool isPlus(){return true;}
    string toString() const {return "+";}
    bool isOper(){return true;}
    int precedence(){return 2;}
};

class MultToken: public Token
{
public:
    bool isMult()){return true;}
    string toString() const {return "*";}
    bool isOper(){return true;}
    int precedence(){return 3;}
};

class DivToken: public Token
{
public:
    bool isDiv(){return true;}
    string toString() const {return "/";}
    bool isOper(){return true;}
    int precedence(){return 4;}
};

class MinusToken: public Token
{
public:
    bool isMinus(){return true;}
    string toString() const {return "-";}
    bool isOper(){return true;}
    int precedence(){return 2;}
};

class Tokenizer
{
private:
    istream *_inp;

public:
    Tokenizer()
    {
        _inp = &cin;
    }

    Token *next()
    {
        if(!_inp) return NULL;
        *_inp>>ws;
        char c = _inp->peek();
        if (c==EOF) return NULL;
        *_inp>>c;

        switch(c)
        {
            case '(': return new LeftBracket();
            case ')': return new RightBracket();
            case '+': return new PlusToken();
            case '-': return new MinusToken();
            case '*': return new MultToken();
            case '/': return new DivToken();
            default: ;
        }

        string buff;
        buff=c;
        do
        {
            char c=_inp->peek();
            if(! isdigit(c) && c!='.') break;
            *_inp>>c;
            buff+=c;
        }while(true)

        return new NumToken(stof(buff));
    }
};

#endif // _TOKENIZER_HPP
