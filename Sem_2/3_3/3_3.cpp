#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int k, temp;
    const int n = 15;
    
    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < k; i++) {
        temp = arr[0];
        for (int j = 0; j < n - 1; j++) {
            arr[j] = arr[j + 1];
        }
        arr[n - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}
