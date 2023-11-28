#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, sum = 0;

	cout << "введите число: ";
	cin >> n;

	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	cout << sum;

	return 0;
}
