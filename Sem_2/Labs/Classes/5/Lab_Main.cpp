#include <string>
#include <iostream>
#include"Object.h"
#include"Person.h"
#include "Student.h"
#include "Vector.h"

using namespace std;

int main(){
    system ("chcp 1251>null");

    Vector v(5);
    Person a;
    cin >> a;
    Student b;
    cin >> b;
    Object* p = &a;
    v.Add(p);
    p = &b;
    v.Add(p);
    cout << v;

    return 0;
}
