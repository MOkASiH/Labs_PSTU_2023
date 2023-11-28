#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");


	int N;
	cout << "¬ведите длину основани€ (натуральное число больше 2)";
	cin >> N;

	for (int i = 1; i <= N; i++) {

		for (int j = 0; j < i; j++) {
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}
