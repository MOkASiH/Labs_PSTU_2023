
# Лабораторная работа №1
Тема : "Работа с двумерными массивами"

# Вариант №0
Заполнить двумерный массив: если сумма номера строки и номера столбца – нечётное число, то такой элемент = 0, все остальные элементы заполняются от 1 до 9 по порядку

# Блок-схема
<image src ="Lab_1.png">


# Код программы

```cpp

##include <iostream>
using namespace std;

int main() {

	int const n = 100;
	int arr[n][n] = { 0 };
	int c, k = 1;
	cin >> c;
	cout << endl;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if ((i + j) % 2 == 0) {
				arr[i][j] = k;
				k++;
			}
			if (k == 10) {
				k = 1;
			}
			cout << arr[i][j] << "  ";
		}
		cout << endl << endl;
	}


	return 0;
}
```
