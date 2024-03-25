#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int partition(int* arr, int left, int right) {
	int pivot = arr[left];
	int i = left - 1, j = right + 1;
	while (1) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j) {
			return j;
		}
		swap(arr[i], arr[j]);

	}
}
void quick_sort(int* arr, int left, int right) {
	if (left < right) {
		int pi = partition(arr, left, right);
		quick_sort(arr, left, pi);
		quick_sort(arr, pi + 1, right);
	}
}



int main() {
	system("chcp 1251 > Null");
	srand(time(0));

	const int size = 25;
	int arr[size];
	int r = rand() % 90;

	cout << "В  сформированном массиве встречаются числа меньше чем " << r << "\n\nСформированный масив: \n";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % r;
		if (i == 0) {
			cout << arr[i];
		}
		else {
			cout << " " << arr[i];
		}
	}
	quick_sort(arr, 0, size - 1);
	cout << "\n\nМассив был отсортирован быстрой сортировкой по Хоару\n";
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << arr[i];
		}
		else {
			cout << " " << arr[i];
		}
	}

	return 0;
}
