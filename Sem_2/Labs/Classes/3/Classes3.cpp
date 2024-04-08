#include <iostream>
#include "Pair.h"

using namespace std;

Pair& operator+(int f, Pair& p) { 
    return p + f;
}
Pair& operator+(double s, Pair& p) { 
    return p + s;
}

int main(){
    Pair a;
    Pair b(12,2.5);
    Pair c(b);
    
    b + 24;
    b + 0.24;

    a = (b - c);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    return 0;
}
