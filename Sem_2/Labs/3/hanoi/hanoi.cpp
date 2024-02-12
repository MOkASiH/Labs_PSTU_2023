#include <iostream>
using namespace std;

void hanoi(int c, int start, int end, int mid) {
    if (c > 0) {
        hanoi(c - 1, start, mid, end);

        cout << "переместить диск " << c << " с " << start << " на столбик " << end << endl;

        hanoi(c - 1, mid, end, start);
    }
}

int main() {
    setlocale(LC_ALL, "rus");

    int start = 1, end = 3, mid = 2, c;

    cout << "Количество дисков:" << endl;
    cin >> c;

    hanoi(c, start, end, mid);

    return 0;
}