#pragma once
#include <iostream>
using namespace std;
class Expression
{
public:
    virtual double calculate() = 0;
    virtual ~Expression() = 0;
};
Expression::~Expression() {}