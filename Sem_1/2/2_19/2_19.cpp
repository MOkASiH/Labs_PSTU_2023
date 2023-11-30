#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, sum = 0;
	cout << "введиите число: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) {
			sum -= i;
		}
		else {
			sum += i;
		}

	}

	cout << sum;
	return 0;
}