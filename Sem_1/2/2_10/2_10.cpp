#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, s, max;
	cout << "введиите кол-во символов: ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		if (i == 1) {
			max = s;
		}
		if (s >= max) {
			max = s;
		}
	}
	cout << max;

	return 0;
}