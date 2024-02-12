#include <iostream>
using namespace std;

int main() {

	int const n = 100;
	int arr[n][n] = { 0 };
	int c;
	cin >> c;
	cout << endl;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if (i >= j) {
				arr[i][j] = (i - j + 1) % 10;
			}
			if (i - j >= 9) {
				arr[i][j] = (i - j + 1) % 10 + 1;
			}
			cout << arr[i][j] << "  ";
		}
		cout << endl << endl;
	}


	return 0;
}
