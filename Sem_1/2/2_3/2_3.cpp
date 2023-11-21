#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int sum = 0;
	int N, c;

	cout << "¬ведите число: ";
	cin >> N;

	for (int i = 1; i <= N; i++) {

		int pr = 1;

		for (int k = N; k <= N * 2; k++) {

			pr *= k;
		}

		sum += pr;

	}
	cout << sum;

	return 0;
}