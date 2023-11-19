#include <iostream>

using namespace std;

int main() {

	float a, b, c;
	cin >> a >> b;

	if (b == 0) {
		cout << "cannot";
	}
	else {
		c = a / b;
		cout << c;
	}


	return 0;
}