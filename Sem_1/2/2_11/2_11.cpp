#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    int n, c;
    bool positive = false;
    bool negative = false;

    cout << "Введите кол-во чисел: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        
        cout << "Введите " << i << " число: ";
        cin >> c;

        if (negative == false and positive == false) {
            if (c > 0) {
                positive = true;
            }
            else if (c < 0) {
                negative = true;
            }
        }
    }

    if (positive == true) {
        cout << "Положительное раньше";
    }
    else if (negative == true) {
        cout << "Отрицательное раньше";
    }
    else{
        cout << "Все нули";
    }
    return 0;
}