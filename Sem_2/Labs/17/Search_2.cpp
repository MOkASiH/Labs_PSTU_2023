#include <iostream>
#include <string>

using namespace std;

const int CHAR_NUM = 256;

void calc_char_table(string str, int size, int char_table[CHAR_NUM]) {
    for (int i = 0; i < CHAR_NUM; i++) {
        char_table[i] = -1;
    }
    for (int i = 0; i < size; i++) {
        char_table[(int)str[i]] = i;
    }
}
void boyer_moore_search(string str, string pattern) {
    int str_size = str.size();
    int pattern_size = pattern.size();

    int shift_table[CHAR_NUM];

    calc_char_table(str, pattern_size, shift_table);

    int shift = 0;

    while (shift <= (str_size - pattern_size)) {
        int i = pattern_size - 1;

        while (i >= 0 and pattern[i] == str[shift + i]) {
            i--;
        }

        if (i < 0) {
            cout << "Паттерн найден на позиции " << shift + 1 << endl;
            if ((shift + pattern_size) < str_size) {
                shift += pattern_size - shift_table[(int)str[shift + pattern_size]];
            }
            else {
                shift++;
            }
        }
        else {
            shift += max(1, i - shift_table[(int)str[shift + i]]);
        }
    }
}

int* prefix(string pattern, int size) {
    int* lps = new int[size];
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < size) {
        if (pattern[i] == pattern[len]) {
            lps[i] = len;
            len++;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}
void KMP(string str, string pattern) {
    int str_size = str.size();
    int pattern_size = pattern.size();
    int* lps = prefix(pattern, pattern_size);
    int pattern_index = 0;
    int str_index = 0;

    while ((str_size - str_index) >= (pattern_size - pattern_index)) {
        if (pattern[pattern_index] == str[str_index]) {
            str_index++;
            pattern_index++;
        }

        if (pattern_index == pattern_size) {
            cout << "Паттерн найден на позиции " << str_index - pattern_index + 1 << endl;
            pattern_index = lps[pattern_index - 1];
        }
        else if (str_index < str_size and pattern[pattern_index] != str[str_index])
        {
            if (pattern_index != 0) {
                pattern_index = lps[pattern_index - 1];
            }
            else {
                str_index++;
            }
        }
    }
}


int main() {
    system("chcp 1251>null");

    string str, pattern;

    cout << "Введите строку внутри которой необходимо выполнить поиск\n";
    getline(cin, str);

    cout << "Введите искомую подстроку: \n";
    getline(cin, pattern);

    cout << "Поиск алгоритмом Бойера-Мура: \n";
    boyer_moore_search(str, pattern);

    cout << "Поиск алгоритмом Кнута-Морриса-Пратта: \n";
    KMP(str, pattern);

    return 0;
}