#include<iostream>
#include<ctime>

using namespace std;

int triangle(int c, ...) {
    int* p = &c + 2;
    int t = 0, r = c;
    int arr[100];

    for (int i = 0; c != 0; i++) {
        arr[i] = *p;
        c--;
        p += 2;
    }
    c = r;
    cout << endl << "Тройки, которые могут быть длинами сторон треугольника: " << endl;
    for (int i = 0; i < c - 2; i++) {
        if (arr[i] < arr[i + 1] + arr[i + 2] and arr[i + 1] < arr[i] + arr[i + 2] and arr[i + 2] < arr[i + 1] + arr[i]) {
            cout << arr[i] << " " << arr[i + 1] << " " << arr[i + 2] << endl;
            t++;
        }
    }

    cout << "Количество таких троек = ";

    return t;
}



int main() {
    setlocale(LC_ALL, "RU");

    int x = 27, y = 30, z = 93;

    cout << triangle(3, x, y, z) << endl;
    cout << triangle(9, 36, 14, 87, 42, 90, 12, 62, 30, 21) << endl;
    cout << triangle(11, 9, 76, 72, 96, 26, 30, 25, 53, 81, 7, 37) << endl;


    return 0;
}
