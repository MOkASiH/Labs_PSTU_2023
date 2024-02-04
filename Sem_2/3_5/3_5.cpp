#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    const int n = 5;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    cout << max;


    return 0;
}
