#ifndef _EXPR_HPP_
#define _EXPR_HPP_

class Expr
{
public:
    Expr() {}
    virtual float eval() = 0;
};

class Const: public Expr
{
private:
    float _val;

public:
    Const(float v): _val(v) {}
    float eval() {return _val;}
};

class BinaryExpr: public Expr
{
protected:
    Expr *_left;
    Expr *_right;

public:
    BinaryExpr(Expr *l;Expr *r): Expr(), _left(l), _right(r) {}
};

class Plus: public BinaryExpr
{
public:
    Plus(Expr *l;Expr *r): BinaryExpr(l,r) {}
    float eval() { return _left->eval() + _right->eval();}
};

class Mult: public BinaryExpr
{
public:
    Mult(Expr *l;Expr *r): BinaryExpr(l,r) {}
    float eval() { return _left->eval() * _right->eval();}
};


#endif // _EXPR_HPP_
