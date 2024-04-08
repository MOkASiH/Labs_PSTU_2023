#include <iostream>
#include <string>

using namespace std;

class Payday {

    string ln_fn_p;
    double salary;
    int reward;

public:
    Payday(string, double, int);

    Payday();

    Payday(const Payday&);

    ~Payday();

    string get_fio();
    double get_salary();
    int get_reward();

    void set_fio(string);
    void set_salary(double);
    void set_reward(int prem);

    void show();
};