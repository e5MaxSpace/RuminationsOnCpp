#include <iostream>

#include "picture.h"

using namespace std;

char* init[] = {"Paris", "in the", "Spring"};

int main()
{
    cout << "Hello World!" << endl;

    Picture p(init, 3);
    cout << p << endl;

    Picture p2;
    p2 = p;
    cout << p2 << endl;

    Picture q = frame(p);
    cout << q << endl;

    Picture h = p | q;
    cout << h << endl;

    Picture v = p & q;
    cout << v << endl;

    return 0;
}

