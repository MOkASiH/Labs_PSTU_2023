#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int n, f = 1;
	int* fptr = &f;

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		*fptr *= i;
	}
	cout << f;


	return 0;
}
