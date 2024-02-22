#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<ctime>
#include<cctype>



using namespace std;

int count(int* arr, int n) {
    int k = 0;

    for (int i = 0; i < n; i++)
        if (arr[i] % 2 == 0) {
            k++;
        }
    return k;
}

int count(char* arr) {
    int k = 0;

    for (int i = 0; i < 100; i++) {
        if (arr[i] == 'a' and arr[i - 1] == ' ') {
            k++;
        }
    }
    if (arr[0] == 'a') {
        k++;
    }

    return k;
}



int main() {
    setlocale(LC_ALL, "RU");
    srand(time(0));

    int n = 40;
    int arrn[40];
    char arrs[1000];
    string text;

    cout << "Введите количество чисел (до 100)" << endl;
    for (int i = 0; i < n; i++) {
        arrn[i] = rand() % 100;
        cout << arrn[i] << "  ";
    }
    cout << endl;

    cout << "В данном массиве " << count(arrn, n) << " четных чисел" << endl << endl;

    cout << "Введите текст (до 1000 символов)" << endl;
    getline(cin, text);
    strcpy(arrs, text.c_str());
    for (int i = 0; i < strlen(arrs); i++) {
        arrs[i] = tolower(arrs[i]);
    }
    cout << endl;
    cout << "Количество слов, которые начинаются на а = " << count(arrs);

    return 0;
}