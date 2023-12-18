//f(x) = 3x - 4lnx - 5
//f'(x) = 3 - 4/x 
// f''(x) = 4/x^2
//[2;4]
#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double x = 4, xprev = 0; //x = b = 4 ò.ê. f(b)*f''(b) >0
	double eps = 0.000001;

	while (abs(x - xprev) > eps) {
		xprev = x;

		x = xprev - (3 * xprev - 4 * log(xprev) - 5) / (3 - 4 / x);
	}
	cout << x;


	return 0;
}