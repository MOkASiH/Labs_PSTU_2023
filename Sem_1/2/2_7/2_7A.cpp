#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n;
	cout << "введиите площадь квадрата(учитывая, что из площади нацело вычисляется корень и минимальная площадь 4): ";
	cin >> n;
	int s = sqrt(n);

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}