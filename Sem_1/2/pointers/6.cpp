#include <iostream> // не вывез с русскими
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU");

    int c = 0, v = 0;
    string w;

    cout << "Введите строку" << endl;
    cin >> w;

    const char* pt = w.c_str();

    for (int i = 0; i < w.length(); i++)
    {
        if (*pt == 'A' or *pt == 'E' or *pt == 'I' or *pt == 'O' or *pt == 'Y' or *pt == 'U' or *pt == 'a' or *pt == 'e' or *pt == 'i' or *pt == 'y' or *pt == 'o' or *pt == 'u')
        {
            v++;
        }
        else {
            c++;
        }

        pt++;
    }

    cout << "гласных " << v;
    cout << "согласных " << c;

    return 0;
}