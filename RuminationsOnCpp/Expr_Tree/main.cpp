#include <iostream>

#include "expr.h"

using namespace std;

int main()
{
    cout << "Hello World!" << endl;

    Expr t1 = Expr(5);
    cout << t1 << "=" << t1.eval() << endl;

    Expr t2 = Expr("-", 5);
    cout << t2 << "=" << t2.eval() << endl;

    Expr t3 = Expr("*", Expr("-", 5), Expr("+", 3, 4)) ;
    cout << t3 << "=" << t3.eval() << endl;

    return 0;
}

