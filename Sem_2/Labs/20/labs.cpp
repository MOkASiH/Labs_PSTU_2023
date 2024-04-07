#include "Payday.h"
#include <iostream>
#include <math.h>

using namespace std;

Payday make_payday() {
    string fio;
    double zp;
    int premia;

    cout << "Введите ФИО работника\n";
    getline(cin,fio);

    cout << "Введите зарплату работника\n";
    cin >> zp;

    cout << "Введите премию работника в процентах от зарплаты\n";
    cin >> premia;

    Payday p(fio, zp, premia);
    return p;
}
    
void print_payday(Payday p) {
    p.show();
}


int main() {
    system("chcp 1251>null");
    
    Payday p1;
    p1.show();
    cout << endl;

    Payday p2("Зубенко Михаил Петрович", 800000, 30);
    p2.show();
    cout << endl;

    Payday p3(p2);
    p3.show();
    cout << endl;
    p3.set_fio("Бородач Александр Родионович");
    p3.set_salary(9000);
    p3.set_reward(0);
    print_payday(p3);
    cout << endl;
    cout << endl;

    p1 = make_payday();
    p1.show();
    cout << endl;

  

    return 0;
}