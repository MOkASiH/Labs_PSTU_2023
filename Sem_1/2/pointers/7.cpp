#include <iostream> 
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU");

    int n;
    int* ptr = &n;

    cin >> *ptr;

    cout << n;

    return 0;
}