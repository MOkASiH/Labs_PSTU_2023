#include<iostream>
#include<math.h>


using namespace std;

class Progression {
public:

    double first;
    int second;
    int j;

    double element() {
        double j_elem;
        for (int i = 1; i <= j; i++) {
            j_elem = first * pow(second, j);
        }
        return j_elem;
    }
};

int main() {
    system("chcp 1251>null");

    double a;
    int r;
    int c;
    double result;

    cout << "¬ведите дробное число - первый элемент последовательности\n";
    cin >> a;

    cout << "\n¬ведите целое число - посто€нное отношение\n";
    cin >> r;

    cout << "\n¬ведите целое число - номер элемента последовательности\n";
    cin >> c;

    Progression progress;
    progress.first = a;
    progress.second = r;
    progress.j = c;

    result = progress.element();
    cout << endl << c << " элемент последовательности = ";
    cout << result;


    return 0;
}