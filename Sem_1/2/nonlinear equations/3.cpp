//f(x) = 3x - 4lnx - 5
//f'(x) = 3 - 4/x 
// f''(x) = 4/x^2
//[2;4]
//r = max(f'(a), f'(b)) = max(1, 2) = 2
//-1/r < λ < 0 если f'(x) > 0
// 0 < λ < 1/r если f'(x) < 0
//берем любую удобную λ
//λ = -1/5 = -0.2

#include <iostream>
#include <cmath>

using namespace std;

int main() {

	double x = 2, lambda = -0.2, xprev = 0, eps = 0.000001;

	while (abs(x - xprev) > eps) {
		xprev = x;
		x = xprev + lambda * (3 * xprev - 4 * log(xprev) - 5);
	}
	cout << x;


	return 0;
}