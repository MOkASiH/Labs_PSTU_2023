#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");


	int N;
	cout << "¬ведите длину основани€ (нечетное число больше 3)";
	cin >> N;
	int spaces = N / 2;
	int stars = 1;

	for (int i = 0; i < (N+1)/2; i++) {
		
		for (int j = 0; j < spaces; j++) {
			cout << " ";
		}
		
		spaces--;
		
		for (int j = 0; j < stars; j++) {
			cout << "*";
		}
		
		stars += 2;
		cout << endl;
	}
	
	
	return 0;
}