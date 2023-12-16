#include <iostream>

using namespace std;

int main() {

	float a, b, sum;
	float* aptr, * bptr;

	cin >> a >> b;
	aptr = &a;
	bptr = &b;

	sum = *aptr + *bptr;

	cout << sum;


	return 0;
}
