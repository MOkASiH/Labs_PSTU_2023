#include<iostream>
#include"Payday.h"

Payday::Payday(string fio, double pay, int prem) {
    ln_fn_p = fio;
    salary = pay;
    reward = prem;
}

Payday::Payday() {
    ln_fn_p = "";
    salary = 0;
    reward = 0;
}

Payday::Payday(const Payday& p) {
    ln_fn_p = p.ln_fn_p;
    salary = p.salary;
    reward = p.reward;
}

Payday::~Payday() {}

string Payday::get_fio() {
    return ln_fn_p;
}
double Payday::get_salary() {
    return salary;
}
int Payday::get_reward() {
    return reward;
}

void Payday::set_fio(string fio) {
    ln_fn_p = fio;
}
void Payday::set_salary(double zp) {
    salary = zp;
}
void Payday::set_reward(int prem) {
    reward = prem;
}

void Payday::show() {
    cout << "\nФИО работника: " << ln_fn_p;
    cout << "\nЗП работника: " << salary;
    cout << "\nПремия работника: " << reward;
}