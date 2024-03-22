#include<iostream>
#include<string>
#include<fstream>

using namespace std;

system("chcp 1251>null");

struct StackElem {
    char data = 0;
    StackElem* downer = nullptr;
};
struct Stack
{
    StackElem* top = nullptr;
    int size = 0;
    void push(char data) {
        StackElem* newElem = new StackElem;
        newElem->data = data;
        newElem->downer = top;
        top = newElem;
        size++;
    }
    char pop() {
        if (size == 0) {
            cout << "Стек пуст, действие невозможно" << endl;
            return NULL;
        }
        char value = top->data;
        StackElem* tmp = top;
        top = top->downer;
        size--;
        delete tmp;
        return value;
    }
}s;


void print(Stack& s) {
    if (s.size == 0) {
        cout << "Стек пуст." << endl;
        return;
    }
    Stack tmp;
    char datatmp, sized = s.size;
    for (int i = 0; i < sized; i++) {
        datatmp = s.pop();
        tmp.push(datatmp);
    }
    for (int i = 0; i < sized; i++) {
        datatmp = tmp.pop();
        s.push(datatmp);
        cout << datatmp;
    }
}

void add(Stack& s, char data, int n) {
    Stack tmp;
    char datatmp;
    int sized = s.size;
    for (int i = 0; i <= sized - n; i++) {
        datatmp = s.pop();
        tmp.push(datatmp);
    }
    s.push(data);
    for (int i = 0; i <= sized - n; i++) {
        datatmp = tmp.pop();
        s.push(datatmp);
    }
}

void del(Stack& s, int n) {
    Stack tmp;
    char datatmp;
    int sized = s.size;
    for (int i = 0; i < sized - n; i++) {
        datatmp = s.pop();
        tmp.push(datatmp);
    }
    s.pop();
    for (int i = 0; i < sized - n; i++) {
        datatmp = tmp.pop();
        s.push(datatmp);
    }
}

bool search(Stack& s, char da) {
    Stack tmp;
    char datatmp;
    bool flag = false;
    int size = s.size;
    for (int i = 0; i < size; i++) {
        datatmp = s.pop();
        tmp.push(datatmp);
    }
    for (int i = 0; i < size; i++) {
        datatmp = tmp.pop();
        s.push(datatmp);
        if (datatmp == da) {
            flag = true;
        }
    }
    return flag;
}

void saver(Stack& s) {
    ofstream file1("C:\\Users\\MOkASiH\\Desktop\\sem_2\\11\\save.txt");
    if (file1) {
        Stack tmp;
        char datatmp;
        int size = s.size;
        for (int i = 0; i < size; i++) {
            datatmp = s.pop();
            tmp.push(datatmp);
        }
        for (int i = 0; i < size; i++) {
            datatmp = tmp.pop();
            s.push(datatmp);
            file1 << datatmp;
        }
    }

    else {
        cout << "Файл не открылся";
    }
    file1.close();
}

void killer(Stack& s) {
    int size = s.size;
    for (int i = 0; i < size; i++) {
        s.pop();
    }
}

void load(Stack& s) {
    ifstream file1("C:\\Users\\MOkASiH\\Desktop\\sem_2\\11\\save.txt");
    if (file1) {
        cin.ignore();
        string f;
        getline(file1, f);
        for (int i = 0; i < f.length(); i++) {
            s.push(f[i]);
        }
        file1.close();
    }
    else {
        cout << "Файл не открыт";
    }
}




int main() {
    int p, d;
    char ad;
    string f;
    cout << "Введите символы которыми хотите заполнить стек\n";
    getline(cin, f);
    for (int i = 0; i < f.length(); i++)
    {
        s.push(f[i]);
    }

    cout << "Сформированный стек\n";
    print(s);

    cout << "\nВведите количество элементов которые хотите добавить\n";
    cin >> d;
    cout << "Введите позицию на которую хотите добавить элементы\n";
    cin >> p;
    cout << "Введите элементы которые хотите добавить\n";
    cin.ignore();
    getline(cin, f);
    for (int i = 0; i < d; i++) {
        add(s, f[i], p + i);
    }
    print(s);

    cout << "\nВведите количество элементов которые хотите удалить\n";
    cin >> d;
    cout << "Введите позицию с которой хотите удалить элементы\n";
    cin >> p;
    for (int i = 0; i < d; i++) {
        del(s, p);
    }
    print(s);


    cout << "\nВведите элемент, поиск, которого необходимо выполнить\n";
    cin >> ad;
    if (search(s, ad) == 1) {
        cout << "Данный элемент есть в структуре\n";
    }
    else {
        cout << "Данного элемента нет в структуре\n";
    }

    saver(s);
    cout << "Структура сохранена в файл\n";
    killer(s);
    cout << "Cтруктура удалена\n";
    print(s);

    load(s);
    cout << "Структура загружена из файла\n";
    print(s);

    return 0;
}