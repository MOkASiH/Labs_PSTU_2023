#include <iostream>
#include <cmath>

// 1 + 2* (x/2) + ... + (n^2+1/n!)* (x/2)^n 

using namespace std;

int fac(int n) {
	if (n < 1) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	return n * fac(n - 1);
}
int sum(int n, double x) {
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 1 + 2 * (x / 2);
	}
	return ((pow(n, 2) + 1) / fac(n)) * pow(x / 2, n) + sum(n - 1, x);
}

int main() {

	int n;
	double x, s;

	cin >> n >> x;
	cout << endl;

	fac(n);
	s = sum(n, x);

	cout << "sum: " << endl;
	cout << s;


	return 0;
}
