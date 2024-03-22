#include <iostream>
#include <ctime>

using namespace std;


int main() {
	system("chcp 1251 >Null");
	srand(time(0));

	int r = rand() % 1000;
	const int size = 25;
	int arr[size];

	cout << "Исходный массив: \n";

	for (int i = 0; i < size; i++) {
		arr[i] = rand() % r;
		cout << arr[i] << " ";
	}
	cout << endl;
	for (int w = size / 2; w > 0; w /= 2) {
		for (int i = w; i < size; i++) {
			int tmp = arr[i];
			int j;
			for (j = i; j >= w and arr[j - w] > tmp; j -= w) {
				arr[j] = arr[j - w];
			}
			arr[j] = tmp;
		}
	}

	cout << "Массив отсортирован с помощью сортировки Шелла: \n";

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}