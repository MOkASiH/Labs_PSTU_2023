#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, s, max, min;
	cout << "�������� ���-�� �������� (������ ����): ";
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cout << "������� " << i << " ������������� �����: ";
		cin >> s;
		if (i == 1) {
			max = s;
			min = s;
		}
		if (s >= max) {
			max = s;
		}
		if (s <= min) {
			min = s;
		}
	}
	cout << max + min;

	return 0;
}