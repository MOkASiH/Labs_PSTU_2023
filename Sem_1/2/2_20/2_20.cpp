#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	float n, s, a;
	int o;

	bool flag = false;
	cout << "�������� �����: ";
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {

		a = sin(n + i / n);
		a = round(a * 100) / 100;
		cout << a << ", ";

		if (a == s) {
			flag = true;
		}
	}

	if (flag == true) {
		cout << "��������";
	}
	else {
		cout << "�� ��������";
	}

	return 0;
}