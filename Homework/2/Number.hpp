#pragma once
#include "Expression.hpp"

class Number : public Expression {
public:
    Number(double value) : value(value) {}
    double calculate() { return value; }
    
private:
    double value;
};