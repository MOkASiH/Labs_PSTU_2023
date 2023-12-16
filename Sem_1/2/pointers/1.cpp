#include <iostream>

using namespace std;

int main() {

	int a, b, temp;
	int* aptr, * bptr;

	cin >> a;
	aptr = &a;
	temp = *aptr;

	cin >> b;
	bptr = &b;
	*aptr = *bptr;
	bptr = &temp;

	cout << *aptr << endl << *bptr;


	return 0;
}
