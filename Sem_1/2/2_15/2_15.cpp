#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, s;
	bool flag = false;

	cout << "������� �����: ";
	cin >> n;
	cout << "������� ����� ��� ��������: ";
	cin >> s;

	while (n != 0) {
		if (s == n % 10) {
			flag = true;
		}
		n /= 10;
	}
	if (flag == true) {
		cout << "����";
	}
	else {
		cout << "���";
	}

	return 0;
}
