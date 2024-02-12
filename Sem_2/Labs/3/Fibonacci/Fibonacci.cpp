#include <iostream>

using namespace std;

int fib(int f) {

	if (f < 1) {
		return 0;
	}
	else if (f == 1) {
		return 1;
	}
	return fib(f - 1) + fib(f - 2);

}

int main() {

	int n = 10;

	for (int i = 0; i < n; i++) {
		cout << fib(i) << " ";
	}

	return 0;
}