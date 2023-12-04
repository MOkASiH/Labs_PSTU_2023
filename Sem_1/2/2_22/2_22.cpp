#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int k = 0;
	float max, a, n;

	cin >> n;

	for (int i = 1; i <= n; i++) {

		a = sin(n + i / n);

		if (i == 1) {
			max = a;
			k = i;
		}
		if (a > max) {
			max = a;
			k = i;
		}

	}
	cout << "максимальный элемент = " << max << endl << "его порядковый номер = " << k;

	return 0;
}
