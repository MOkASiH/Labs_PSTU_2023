#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int sum = 1;
	int q, c;

	cout << "������� ���-�� �����: ";
	cin >> q;

	for (int i = 1; i <= q; i++) {
		cout << "������� " << i << " ���������: ";
		cin >> c;

		sum *= c;
	}
	cout << sum;

	return 0;
}
