#include <iostream>
#include <ctime>

using namespace std;

const int sze = 25;
int arr_t[26];
int count_point;

void multiphase_sorting(int* arr, int size) {
    bool swapped = true;
    int tmp = size;
    while (tmp > 1 or swapped == true) {
        tmp = (tmp * 10) / 13;

        if (tmp < 1) {
            tmp = 1;
        }
        swapped = false;
        for (int i = 0; i < size - tmp; i++) {
            if (arr[i] > arr[i + tmp]) {
                swap(arr[i], arr[i + tmp]);
                swapped = true;
            }
        }
    }
}


void merge(int c[], int d[], int l, int m, int r) {
    int i = l, j = m + 1, k = r;

    while ((i <= m) && (j <= r)) {
        if (c[i] <= c[j])
            d[l++] = c[i++];
        else
            d[l++] = c[j++];
    }
    if (i > m) {
        for (int q = j; q <= r; q++)
            d[l++] = c[q];
    }
    else {
        for (int p = i; p <= m; p++)
            d[l++] = c[p];
    }
}
void merge_pass(int x[], int y[], int s, int n) {
    int i = 0;
    while (i <= count_point - 2 * s) {
        int r = ((i + 2 * s) < count_point) ? arr_t[i + 2 * s] : n;

        merge(x, y, arr_t[i], arr_t[i + s] - 1, r - 1);
        i = i + 2 * s;
    }
    if (i + s < count_point) {
        merge(x, y, arr_t[i], arr_t[i + s] - 1, n - 1);
    }
    else  if (i < count_point) {
        for (int j = arr_t[i]; j <= n - 1; j++) {
            y[j] = x[j];
        }
    }
}
void merge_sort(int a[], int n) {
    int* b = new int[n];
    int s = 1;
    while (s < count_point) {
        merge_pass(a, b, s, n);
        s += s;
        merge_pass(b, a, s, n);
        s += s;
    }
}
void split_point(int a[], int b[], int n, int& m) {
    int j = 0;
    b[j++] = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            b[j++] = i + 1;
        }
    }
    m = j;
}


void print_array(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void menu(int* arr, int size) {
    int choise;

    cout << "\n\nВыберите метод сортировки: \n";
    cout << "1. Многофазная сортировка\n";
    cout << "2. Eстественная сортировка\n";
    cin >> choise;
    cout << "=======================================================\n\n";

    switch (choise) {
    case 1: {
        multiphase_sorting(arr, size);
        cout << "Отсортированный массив: \n";
        print_array(arr, size);
        break;
    }
    case 2: {
        split_point(arr, arr_t, sze, count_point);
        merge_sort(arr, sze);
        cout << "Отсортированный массив: \n";
        print_array(arr, size);
        break;
    }
    default: {
        cout << "Введите соответствующий номер пунтка меню\n";
        menu(arr, size);
        break;
    }
    }

}
int main() {
    system("chcp 1251>null");
    srand(time(0));

    const int size = 25;
    int arr[size];
    int r = rand() % 99 + 2;

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % r;
    }

    cout << "В сформированном массиве встречаются числа меньше " << r << endl;
    cout << "Сформированный массив \n";
    print_array(arr, size);

    menu(arr, size);


    return 0;
}