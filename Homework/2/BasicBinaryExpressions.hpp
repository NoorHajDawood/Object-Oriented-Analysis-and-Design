#pragma once
#include "BinaryExpression.hpp"

class Plus : public BinaryExpression {
public:
    Plus(shared_ptr<Expression> left, shared_ptr<Expression> right) : BinaryExpression(left, right) {}
    double calculate() { return getLeft()->calculate() + getRight()->calculate(); }
    Expression* clone() { return new Plus(*this); }
};

class Minus : public BinaryExpression {
public:
    Minus(shared_ptr<Expression> left, shared_ptr<Expression>right) : BinaryExpression(left, right) {}
    double calculate() { return getLeft()->calculate() - getRight()->calculate(); }
    Expression* clone() { return new Minus(*this); }
};

class Div : public BinaryExpression {
public:
    Div(shared_ptr<Expression>left, shared_ptr<Expression>right) : BinaryExpression(left, right) {}
    double calculate() 
    { 
        if(getRight()->calculate() == 0)
            throw "Divition by zero!";
        return getLeft()->calculate() / getRight()->calculate(); 
    }
    Expression* clone() { return new Div(*this); }
};

class Mul : public BinaryExpression {
public:
    Mul(shared_ptr<Expression> left, shared_ptr<Expression> right) : BinaryExpression(left, right) {}
    double calculate() { return getLeft()->calculate() * getRight()->calculate(); }
    Expression* clone() { return new Mul(*this); }
};