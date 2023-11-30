#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, x, p = 1;
	double y = 0;
	cout << "введите n: ";
	cin >> n;
	cout << "введите x: ";
	cin >> x;

	for (int i = 0; i <= n; i++) {
		if (i == 0) {
			p *= 1;
		}
		else {
			p *= i;
		}
		y += pow(x, i) / p;
	}

	cout << y;
	return 0;
}