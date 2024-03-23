#include <iostream>
#include <ctime>

using namespace std;

int main() {
	srand(time(0));
	setlocale(LC_ALL, "RU");

	const int n = 100;
	int c, k, z = 1, temp;
	int arr[n];

	cout << "Введите сколько элементов должно быть в массиве(не более 40)" << endl;
	cin >> c;
	cout << endl;


	for (int i = 0; i < c; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << "  ";
	}
	cout << endl << endl;

	cout << "Введите элемент с которого распечатать массив по кольцу влево (не более " << c - 1 << ")" << endl;
	cin >> k;
	cout << endl;

	for (int i = k; i != k - 1; i++) {
		cout << arr[i] << "  ";
		if (i == c - 1) {
			i = -1;
		}
	}
	cout << arr[k - 1] << endl << endl;

	cout << "После каждого элемента, индекс которого кратен 5 добавлен 0" << endl << endl;

	for (int i = 0; i < c; i++) {
		if (i % 5 == 0 and i / 5 != 0) {
			for (int j = c - 1; j > i; j--) {
				arr[j + 1] = arr[j];
			}
			arr[i + 1] = 0;
			c++;
		}
		cout << arr[i] << "  ";
	}
	cout << endl << endl;

	cout << "Полученный массив распечатан начиная с " << k << " елемента по кольцу вправо" << endl << endl;

	for (int i = k; i != k + 1; i--) {
		cout << arr[i] << "  ";
		if (i == 0) {
			i = c;
		}
	}
	cout << arr[k + 1] << endl << endl;



	return 0;
}
