#include <iostream>
#include"classes1.h"
#include<math.h>

void Progression::init(double f, int s) {
    first = f;
    second = s;
}
void Progression::show() {
    std::cout << "first: " << first << "\n";
    std::cout << "second: " << second << "\n";
}
void Progression::read() {
    std::cout << "first: \n";
    std::cin >> first;
    std::cout << "second: \n";
    std::cin >> second;
}

double Progression::element(int j) {
    double j_elem = first * pow(second, j);
    return j_elem;
}