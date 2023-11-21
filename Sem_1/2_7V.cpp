#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n;
	cout << "введиите длину стороны квадрата(минимальная длина 3): ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i == 1 or i == n) {
			for (int j = 1; j <= n; j++) {
				cout << "*";
			}
			cout << endl;
		}
		else {
			cout << "*";
			for (int j = 1; j <= n - 2; j++) {
				cout << " ";
			}
			cout << "*";
			cout << endl;

		}
	}

	return 0;
}