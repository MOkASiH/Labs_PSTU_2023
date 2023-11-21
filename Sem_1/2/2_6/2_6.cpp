#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");


	int N;
	cout << "¬ведите длину основани€ (натуральное число больше 2)";
	cin >> N;
	int spaces = 0;
	int stars = N;

	for (int i = 0; i < N; i++) {

		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}

		spaces += 1;

		for (int j = 0; j < stars; j++) {
			cout << "*";
		}

		stars -= 1;
		cout << endl;
	}


	return 0;
}
