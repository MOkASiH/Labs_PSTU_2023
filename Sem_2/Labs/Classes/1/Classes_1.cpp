#include<iostream>
#include<math.h>
#include "classes1.h"

using namespace std;

Progression make_progression(double f, int s) {
    Progression t;
    t.init(f, s);
    return t;
}

int main() {
    system("chcp 1251>null");

    double a;
    int r;
    int c;
    double result;

    cout << "Введите дробное число - первый элемент последовательности\n";
    cin >> a;

    cout << "\nВведите целое число - постоянное отношение\n";
    cin >> r;

    cout << "\nВведите целое число - номер элемента последовательности\n";
    cin >> c;

    Progression t = make_progression(a, r);
    t.show();
    result = t.element(c);
    cout << endl << c << " элемент последовательности = ";
    cout << result;


    return 0;
}
