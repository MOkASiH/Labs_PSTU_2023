#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void print_array(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		if (i == 0) {
			cout << arr[i];
		}
		else {
			cout << " " << arr[i];
		}
	}
}

void bucket_sort(int* arr, int size) {
	const int bucket_num = 10;
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	max++;

	int** buckets = new int* [bucket_num];
	for (int i = 0; i < bucket_num; i++) {
		buckets[i] = new int[size];
	}

	int bucket_size[bucket_num] = { 0 };
	for (int i = 0; i < size; i++) {
		int bucket_index = arr[i] * bucket_num / max;
		buckets[bucket_index][bucket_size[bucket_index]++] = arr[i];
	}

	for (int i = 0; i < bucket_num; i++) {
		for (int j = 0; j < bucket_size[i]; j++) {
			int tmp = buckets[i][j];
			int k = j - 1;
			while (k >= 0 && buckets[i][k] > tmp)
			{
				buckets[i][k + 1] = buckets[i][k];
				k--;
			}
			buckets[i][k + 1] = tmp;
		}
	}
	int index = 0;
	for (int i = 0; i < bucket_num; i++) {
		for (int j = 0; j < bucket_size[i]; j++) {
			arr[index++] = buckets[i][j];
		}
	}
	delete[] buckets;
}

void counting_sort(int* arr, int size) {
	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	max++;

	int* count = new int[max];
	int* output = new int[size];

	for (int i = 0; i < max; i++) {
		count[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		count[arr[i]]++;
	}
	for (int i = 1; i < max; ++i) {
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < size; i++) {
		arr[i] = output[i];
	}
	delete[] count;
	delete[] output;

}

void merge(int* arr, int left, int mid, int right) {
	int left_size = mid - left + 1;
	int right_size = right - mid;
	int* left_arr = new int[left_size];
	int* right_arr = new int[right_size];

	for (int i = 0; i < left_size; i++) {
		left_arr[i] = arr[left + i];

	}
	for (int i = 0; i < right_size; i++) {
		right_arr[i] = arr[mid + 1 + i];

	}

	int left_index = 0, right_index = 0, merged_index = left;
	while (left_index < left_size && right_index < right_size) {
		if (left_arr[left_index] <= right_arr[right_index]) {
			arr[merged_index] = left_arr[left_index];
			left_index += 1;
		}
		else {
			arr[merged_index] = right_arr[right_index];
			right_index += 1;
		}
		merged_index += 1;
	}

	while (left_index < left_size) {
		arr[merged_index] = left_arr[left_index];
		merged_index += 1;
		left_index += 1;
	}

	while (right_index < right_size) {
		arr[merged_index] = right_arr[right_index];
		merged_index += 1;
		right_index += 1;
	}

	delete[] left_arr;
	delete[] right_arr;
}
void merge_sort(int* arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid);
		merge_sort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

int partition(int* arr, int low, int high, int pivot) {
	int pind = low;
	for (int i = low; i <= high; i++) {
		if (arr[i] <= pivot) {
			swap(arr[pind], arr[i]);
			pind++;
		}
	}
	pind--;
	return pind;
}
void quick_sort(int* arr, int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int pi = partition(arr, low, high, pivot);
		quick_sort(arr, low, pi - 1);
		quick_sort(arr, pi + 1, high);
	}
}


void menu(int* arr, int size, int r) {
	int method_of_sort;
	int flag = 1;

	cout << "\n\nВыберите метод сортировки: \n";
	cout << "1. Блочная сортировка\n";
	cout << "2. Сортировка подсчетом\n";
	cout << "3. Сортировка слиянием\n";
	cout << "4. Быстрая по Ломуто\n";
	cin >> method_of_sort;
	cout << "======================================================================\n\n";

	switch (method_of_sort) {
	case 1: {
		if (r < 30) {
			cout << "Данная сортировка неэффективна для данного массива, уверены что хотите использовать её? (1 - да, 0 - нет)" << endl;
			cin >> flag;
		}
		if (flag == 1) {
			bucket_sort(arr, size);
			print_array(arr, size);
		}
		else {
			menu(arr, size, r);
		}
		return;
	}
	case 2: {
		if (r > 12) {
			cout << "Данная сортировка неэффективна для данного массива, уверены что хотите использовать её? (1 - да, 0 - нет)" << endl;
			cin >> flag;
		}
		if (flag == 1) {
			counting_sort(arr, size);
			print_array(arr, size);
		}
		else {
			menu(arr, size, r);
		}
		return;
	}
	case 3: {
		merge_sort(arr, 0, size - 1);
		print_array(arr, size);
		return;
	}
	case 4: {
		quick_sort(arr, 0, size - 1);
		print_array(arr, size);
		return;
	}
	default: {
		cout << "Введите существующий номер пункта меню\n";
		menu(arr, size, r);
		break;
	}
	}
}


int main() {
	system("chcp 1251 > Null");
	srand(time(0));

	const int size = 25;
	int arr[size];
	int r = rand() % 99 + 2;

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

	menu(arr, size, r);



	return 0;
}
