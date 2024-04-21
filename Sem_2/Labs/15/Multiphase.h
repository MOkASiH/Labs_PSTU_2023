#pragma once
#include<iostream>
#include<fstream>

using namespace std;

int n, r = 1;


void OutputM() {
    ifstream M("M.txt");
    int d;
    while (M >> d) {
        cout << d << ' ';
    }
    M.close();
}
void Marge() {
    ofstream M("M.txt");
    ifstream F1("F1.txt");
    ifstream F2("F2.txt");
    int a, b, c1, c2;
    for (int i = 0; i < floor(ceil((double)n / r) / 2); i++) {
        F1 >> a;
        F2 >> b;
        c1 = 1;
        c2 = 1;
        bool cg = true;
        while (cg) {
            if (a < b) {
                M << ' ' << a;
                F1.get();
                cg = !F1.eof() && c1 < r;
                if (cg) {
                    F1 >> a;
                    c1 += 1;
                }
                else {
                    M << ' ' << b;
                    F2.get();
                }
            }
            else {
                M << ' ' << b;
                F2.get();
                cg = !F2.eof() && c2 < r;
                if (cg) {
                    F2 >> b;
                    c2 += 1;
                }
                else {
                    M << ' ' << a;
                    F1.get();
                }
            }
        }
        while (!F1.eof() && c1 < r) {
            F1 >> a;
            M << ' ' << a;
            c1 += 1;
            F1.get();
        }
        while (!F2.eof() && c2 < r) {
            F2 >> a;
            M << ' ' << a;
            c2 += 1;
            F2.get();
        }
    }
    while (F1 >> a) {
        M << ' ' << a;
    }
    F1.close();
    F2.close();
    M.close();
}

void Slice() {
    int cf = 0;
    ifstream M("M.txt");
    ofstream F1("F1.txt");
    ofstream F2("F2.txt");
    int d;
    while (!M.eof()) {
        for (int i = 0; i < r && M >> d; i++) {
            if (cf) {
                F2 << ' ' << d;
            }
            else {
                F1 << ' ' << d;
            }
        }
        M.get();
        cf = (cf + 1) % 2;
    }
    F1.close();
    F2.close();
    M.close();
    Marge();
}