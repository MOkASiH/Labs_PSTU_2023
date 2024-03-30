#include <iostream>
#include <ctime>

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
void sort(int* arr, int left, int right) {
	if (left < right) {
		int pi = partition(arr, left, right);
		sort(arr, left, pi);
		sort(arr, pi + 1, right);
	}
}

void linear_search(int* arr, int size, int key) {
	int* found = new int[0];
	int found_size = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			found[found_size++] = i;
		}
	}
	if (found_size != 0) {
		cout << "Ключ найден на позиции(ях) ";
		for (int i = 0; i < found_size; i++) {
			cout << found[i] + 1 << " ";
		}
	}
	else {
		cout << "Ключ не найден";
	}
	delete[] found;
}

void interpolation_searh(int* arr, int size, int key) {
	if (arr[0] == key) {
		cout << "\nКлюч найден на позиции 1";
	}

	int start = 0, end = size - 1;
	int mid, found = -1;
	while (arr[start] < key and arr[end] >= key) {
		mid = start + ((key - arr[start]) * (end - start)) / (arr[end] - arr[start]);
		if (arr[mid] == key) {
			found = mid;
			break;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}
		else if (arr[mid] > key) {
			end = mid - 1;
		}
	}
	if (found != -1) {
		cout << "\nКлюч найден на позиции " << found + 1;
	}
	else {
		cout << "\nКлюч не найден";
	}
}

void binary_search(int* arr, int size, int key) {
	int start = 0;
	int end = size - 1;

	while (start <= end) {
		int mid = start + (end - start) / 2;

		if (arr[mid] == key) {
			cout << "Ключ найден на позиции " << mid + 1;
			return;
		}
		else if (arr[mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << "Ключ не найден";
}

void menu(int* arr, bool s, int size) {
	int choice, pos, key;
	cout << "\n\nВведите искомое значение\n";
	cin >> key;
	cout << "\n\nВыберите метод поиска: \n";
	cout << "1. Линейный поиск\n";
	cout << "2. Интерполяционный поиск\n";
	cout << "3. Бинарный поиск\n";
	cin >> choice;


	switch (choice) {
	case 1: {
		linear_search(arr, size, key);
		return;
	}
	case 2: {
		interpolation_searh(arr, size, key);
		return;
	}
	case 3: {
		binary_search(arr, size, key);
		return;
	}
	default: {
		cout << "Введите существующий номер пункта меню\n";
		menu(arr, s, size);
		break;
	}
	}
}


int main() {
	system("chcp 1251>null");
	srand(time(0));

	const int size = 10;
	int arr[size];
	int s = -1;

	cout << "\nСформированный массив\n";
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	while (s != 0 and s != 1) {
		cout << "\n\nХотите ли вы отсортировать массив (1-да, 0-нет)\n";
		cin >> s;
		if (s != 0 and s != 1) {
			cout << "нет\n";
		}
	}
	if (s == 1) {
		sort(arr, 0, size - 1);
		cout << "\nОтсортированный массив\n";
		for (int i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
	}
	menu(arr, s, size);

	return 0;
}
