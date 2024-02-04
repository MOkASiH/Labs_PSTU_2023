#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    const int n = 6;
    int c, temp;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}
