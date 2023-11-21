#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n;
	cout << "введиите длину стороны квадрата(минимальная длина 2): ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}