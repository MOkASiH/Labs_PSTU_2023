#include<iostream>
#include<math.h>
#include "classes1.h"

using namespace std;



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

    Progression progress;
    progress.first = a;
    progress.second = r;
    progress.j = c;

    result = progress.element();
    cout << endl << c << " элемент последовательности = ";
    cout << result;


    return 0;
}