#include <iostream>

using namespace std;

int main() {

	int a, b, sum;
	int* aptr, * bptr;

	cin >> a >> b;
	aptr = &a;
	bptr = &b;
	sum = *aptr + *bptr;

	cout << sum;


	return 0;
}
