#include <iostream>
#include <ctime>

using namespace std;

void foo(int arr[350][350], int n, int m) {
    int line = 0, column = 0, max, c;
    int sum[121104] = { 0 };

    for (int i = 0; i < (n - 2) * (m - 2); i++) {
        for (int k = line; k < (line + 3); k++) {
            for (int l = column; l < (column + 3); l++) {
                sum[i] += arr[k][l];
            }
        }
        if (column < m - 2) {
            column++;
        }
        if (line < n - 2 and column == m - 2) {
            line++;
            column = 0;
        }
    }
    max = sum[0];

    for (int i = 0; i < (n - 2) * (m - 2); i++) {
        if (max < sum[i]) {
            max = sum[i];
            c = i;
        }
    }

    column = 0;
    line = 0;

    cout << endl << "Подмассив 3x3, сумма элементов которого максимальна: " << endl << endl;

    for (int i = 0; i < (n - 2) * (m - 2); i++) {
        for (int k = line; k < (line + 3); k++) {
            for (int l = column; l < (column + 3); l++) {
                if (i == c) {
                    cout << arr[k][l] << '\t';
                }
            }
            if (i == c) {
                cout << endl << endl;
            }
        }
        if (column < m - 2) {
            column++;
        }
        if (line < n - 2 and column == m - 2) {
            line++;
            column = 0;
        }
    }

    cout << "Сумма элементов данного подмассива = " << max << endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int n, m, r;
    int arr[350][350] = { 0 };

    cout << "Введите количество строк (не более 350)" << endl;
    cin >> n;
    cout << endl << "Введите количество столбцов (не более 350)" << endl;
    cin >> m;
    cout << endl << "Введите самое большое число, которое может встретиться в массиве (не более 30000)" << endl;
    cin >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            arr[i][j] = rand() % r;
        }
    }

    foo(arr, n, m);

    return 0;
}
