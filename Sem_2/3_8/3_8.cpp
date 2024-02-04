#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int n;
    int arr[100];
    cin >> n;

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;



    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            for (int j = n - 1; j > i - 1; j--) {
                arr[j + 1] = arr[j];
            }
            arr[i] = -1;
            i++;
            n++;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
