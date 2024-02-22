#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    string t = "2415676";
    int l = t.length(), c = stoi(t), temp;
    int arr[100];

    for (int i = 0; i < l; i++) {
        int k = pow(10, (i + 1));
        arr[i] = c % k / (k / 10);
        c = c - c % k;
    }

    cout << endl;

    for (int i = l - 1; i > 0; i--) {
        for (int j = l - 1; j > 0; j--) {
            if (arr[j] > arr[j - 1]) {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
    for (int i = 0; i < l; i++) {
        cout << arr[i];
    }

    return 0;
}
