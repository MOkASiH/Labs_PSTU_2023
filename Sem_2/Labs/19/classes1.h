#pragma once

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