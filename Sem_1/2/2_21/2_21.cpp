#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, last = 0;
	int o;

	bool flag = true;
	cout << "�������� �����: ";
	for (int i = 1; ; i++) {
		cin >> n;
		if (n == 0) {
			break;
		}
		if (last > n) {
			flag = false;
		}

		last = n;
	}
	if (flag == true) {
		cout << "����������";
	}
	else {
		cout << "������������";
	}


	return 0;
}