#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int s = 0;
	float max, a, n;

	cin >> n;

	for (int i = 1; i <= n; i++) {

		a = sin(n + i / n);

		if (i == 1) {
			max = a;
			s += 1;
		}
		if (a > max) {
			max = a;
			s = 0;
		}
		if (max == a) {
			s += 1;
		}

		cout << a << ", " << endl;
	}
	cout << max << "; " << s;

	return 0;
}
