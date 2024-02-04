#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    const int n = 5;
    int temp;
    int arr[n];
    bool flag = true;

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;

    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            flag = false;
        }
    }
    if (flag == true) {
        cout << "Ordered";
    }
    else {
        cout << "Not ordered";
    }


    return 0;
}
 