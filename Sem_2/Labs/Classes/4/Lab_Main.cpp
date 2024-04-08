#include <iostream>
#include"Person.h"
#include "Student.h"

using namespace std;

void f1(Person& p) {
    p.set_name("Толик\n");
}
Person f2() {
    Student a("Артем", 18, "Физическая культура и спорт", 2);
    
    return a;
}

int main(){
    system ("chcp 1251>null");

    Person a;
    cin >> a;
    cout << a;
    cout << endl;
   
    Person b("Саня", 45);
    cout << b;
    cout << endl;

    a = b;
    cout << a;
    cout << endl;
    cout << endl;
 
    Student c;
    cin >> c;
    cout << c;
    cout << endl;

    
    f1(c);
    a = f2();
    cout << a;
    cout << endl;

    
    return 0;
}
