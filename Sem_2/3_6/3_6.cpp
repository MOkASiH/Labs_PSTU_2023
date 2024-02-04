#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    const int n = 5;
    int k = 0;
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 5;
        cout << arr[i] << " ";
    }
    cout << endl;

    int max = arr[0];

    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
            k = 0;
        }

        if (max == arr[i]) {
            k++;
        }
    }
    cout << max << " " << k;


    return 0;
}
