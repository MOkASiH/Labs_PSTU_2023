#include<iostream>
#include<fstream>
#include<time.h>
#include"Multiphase.h"
#include"Natural.h"


using namespace std;


int main() {
    setlocale(LC_ALL, "Rus");
    srand(time(0));
    
    ofstream M("M.txt");
    cout << "Введите размер массива: ";
    cin >> n;
    int* arr = new int[n];
    int d;
    M << ' ';
    cout << "\nСформированный массив: \n";
    for (int i = 0; i < n; i++) {
        int random = rand() % 1000;
        M << random;
        arr[i] = random;
        cout << random << " ";
        if (i < n - 1) {
            M << ' ';
        }
    }
    M.close(); 
    int* count_arr = new int[n];
    for (int i = 0; i < n; i++) {
        count_arr[i] = 0;
    }
    

    int choise;
    cout << "\n\nВыберите способ сортировки\n";
    cout << "1. Многофазная\n";
    cout << "2. Естественная\n";
    cin >> choise;
    cout << "\nОтсортированый массив: \n";
    if (choise == 1) {
        while (r < n) {
            Slice();
            r *= 2;
        }
        OutputM();
    }
    else if (choise == 2) {
        GetBPoint(arr, count_arr, n, ta);
        MergeSort(arr, n, count_arr);
        OutputM();
    }
    else {
        cout << "NO";
    }


    return 0;
}