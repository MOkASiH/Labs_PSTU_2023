#include <iostream>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int p, q, temp;
    const int n = 15;
    
    cin >> p >> q;
    
    int arr[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        cout << arr[i] << " ";
    }
    cout << endl;
    while (q > p) {
        temp = arr[q];
        arr[q] = arr[p];
        arr[p] = temp;
        p++;
        q--;
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }


    return 0;
}
