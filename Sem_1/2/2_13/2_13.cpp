#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	double a, b, c, d;

	cout << "��������� ����� ���: a*x^2 + b*x + c = 0" << endl;
	cout << "������� �: ";
	cin >> a;
	cout << "������� b: ";
	cin >> b;
	cout << "������� c: ";
	cin >> c;

	d = b * b - 4 * a * c;

	if (d < 0) {
		cout << "������� ���";
	}
	else if (d > 0) {
		cout << "x1 = " << (-b + sqrt(d)) / (2 * a) << endl;
		cout << "x2 = " << (-b - sqrt(d)) / (2 * a) << endl;
	}
	else {
		cout << "x = " << -b / 2 * a;
	}

	return 0;
}


