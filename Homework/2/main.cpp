#include <iostream>
#include <memory>
#include "BasicBinaryExpressions.hpp"
#include "Number.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    shared_ptr<Expression> n10(new Number(10));
    shared_ptr<Expression> n2(new Number(2));
    shared_ptr<Expression> n3(new Number(3));
    shared_ptr<Expression> n4(new Number(4));

    shared_ptr<Expression> minus(new Minus(n3, n4));
    shared_ptr<Expression> mul(new Mul(n2, minus));
    shared_ptr<Expression> div(new Div(n10, n2));
    shared_ptr<Expression> plus(new Plus(div, mul));
    
    cout << plus->calculate();
    return 0;
}
