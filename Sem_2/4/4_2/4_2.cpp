#include <iostream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int arr[10][10];
    int sum = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            arr[i][j] = rand() % 100;
            sum += arr[i][j];
        }
        cout << sum << endl;
        sum = 0;
    }

    return 0;
}
