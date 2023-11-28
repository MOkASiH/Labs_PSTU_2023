#include <iostream>
#include <cmath>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n;
	cout << "введиите длину стороны ";
	cin >> n;
	int stars = n;
	int spaces = n / 2;
	int spaces1 = 0;
	int spaces2 = n / 2;
	int c = n * 1.5;
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= spaces; j++) {
			cout << " ";
		}
		spaces -= 1;
		if ((i == 1) or (i == n / 2 + 1) or (i == c)) {
			for (int j = 1; j <= stars; j++) {
				if (j < stars) {
					cout << "* ";
				}
				else {
					cout << "*";
				}
			}
		}
		else {
			cout << "* ";
			for (int j = 1; j <= stars - 2; j++) {
				cout << "  ";
			}
			cout << "*";
		}

		for (int j = 1; j < spaces1; j++) {
			cout << " ";
		}
		if (spaces1 < n / 2 and i < n) {
			spaces1 += 1;
		}
		if (i > 1 and i < n) {
			cout << "*";
		}
		if (i >= n and i < c) {
			cout << "*";
			spaces1 -= 1;
		}
		cout << endl;
	}
	return 0;
}