#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, r = 0;
	cout << "введиите число: ";
	cin >> n;

	while (n > 0) {
		r = 10 * r + n % 10;
		n /= 10;
	}

	cout << r;
	return 0;
}