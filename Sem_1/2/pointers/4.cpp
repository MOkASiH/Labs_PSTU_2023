#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, min, max, temp;
	int* ptr = &temp;

	cout << "���-�� �����" << endl;
	cin >> n;

	cout << "����� �����" << endl;
	cin >> *ptr;

	max = *ptr;
	min = *ptr;

	for (int i = 2; i <= n; i++) {
		cin >> *ptr;

		if (*ptr > max) {
			max = *ptr;
		}
		else if (*ptr < min) {
			min = *ptr;
		}


	}


	cout << max << endl << min;


	return 0;
}