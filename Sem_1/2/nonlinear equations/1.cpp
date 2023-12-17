//3x - 4lnx - 5 = 0
//[2;4]

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double a = 2, b = 4, c;
	double fa, fb, fc;
	double eps = 0.000001;

	while (b - a > eps) {
		c = (a + b) / 2;

		fa = (3 * a - 4 * log(a) - 5);
		fb = (3 * b - 4 * log(b) - 5);
		fc = (3 * c - 4 * log(c) - 5);

		if (fa * fc > 0) {
			a = c;
		}
		else if (fb * fc > 0) {
			b = c;
		}
		else {
			cout << "error" << endl;
		}

	}
	cout << a << endl << b;


	return 0;
}