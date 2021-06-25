#pragma once
#include "Expression.hpp"
#include <memory>
using namespace std;

class BinaryExpression : public Expression {
public:
    BinaryExpression(shared_ptr<Expression> left, shared_ptr<Expression> right) : left(left), right(right) {}
protected:
    shared_ptr<Expression> getLeft() { return left; }
    shared_ptr<Expression> getRight() { return right; }
private:
    shared_ptr<Expression> left;
    shared_ptr<Expression> right;
};