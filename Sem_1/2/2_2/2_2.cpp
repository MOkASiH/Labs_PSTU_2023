#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int sum = 1;
	int q, c;

	cout << "¬ведите кол-во чисел: ";
	cin >> q;

	for (int i = 1; i <= q; i++) {
		cout << "¬ведите " << i << " множитель: ";
		cin >> c;

		sum *= c;
	}
	cout << sum;

	return 0;
}
