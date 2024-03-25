#include <iostream>
#include <string>
#include<fstream>
using namespace std;

struct node {
    char data;
    node* next = nullptr;
    node* prev = nullptr;

};

struct list {
    node* head = nullptr;
    node* tail = nullptr;
}n;

void push(list& list, char& data, int index) {
    node* new_node = new node;
    new_node->data = data;
    if (list.head == nullptr) {
        list.head = new_node;
        list.tail = new_node;
        return;
    }
    node* cur_node = list.head;
    int c = 0;
    while (c != index - 1) {
        cur_node = cur_node->next;
        c++;
    }
    if (cur_node->next != nullptr) {
        cur_node = cur_node->prev;
    }

    new_node->prev = cur_node;

    if (cur_node->next != nullptr) {
        new_node->next = cur_node->next;
        cur_node->next->prev = new_node;
    }
    cur_node->next = new_node;
    list.tail = new_node;
}


void print(list& list) {
    node* cur_node = list.head;

    while (cur_node != nullptr) {
        cout << cur_node->data << ' ';
        cur_node = cur_node->next;
    }
    cout << endl;
}

void del(list& list, int d) {
    if (list.head == nullptr) {
        return;
    }
    node* cur_node = list.head;
    if (d == 1) {
        node* remove = list.head;
        list.head->next->next->prev = list.head;
        list.head = list.head->next;

        delete remove;
        return;
    }

    node* pre_node = nullptr;

    for (int i = 0; i < d - 1; i++) {
        cur_node = cur_node->next;
    }

    cur_node->prev->next = cur_node->next;
    cur_node->next->prev = cur_node->prev;

    node* remove = cur_node;

    delete remove;
}

bool search(list& list, int ad) {
    node* cur_node = list.head;
    bool flag = false;

    while (cur_node != nullptr) {
        if (cur_node->data == ad) {
            flag = true;
        }
        cur_node = cur_node->next;

    }
    return flag;

}

void saver(list& list) {
    ofstream file1("C:\\Users\\MOkASiH\\Desktop\\sem_2\\11\\save.txt");
    if (file1) {
        node* cur_node = list.head;
        while (cur_node != nullptr) {
            file1 << cur_node->data;
            cur_node = cur_node->next;
        }
    }
    else {
        cout << "Файл не открылся";
    }

}

void killer(list& list) {
    node* cur_node = list.head;
    if (list.head == nullptr) {
        return;
    }
    while (cur_node != nullptr) {
        node* remove = cur_node;
        list.head = cur_node->next;
        cur_node = cur_node->next;
        delete remove;
    }
}

void load(list& list) {
    ifstream file1("C:\\Users\\MOkASiH\\Desktop\\sem_2\\11\\save.txt");
    string f;
    cin.ignore();

    if (file1) {
        getline(file1, f);
        for (int i = 0; i < f.length(); ++i) {
            push(n, f[i], i);
        }
    }
    else {
        cout << "Файл не открылся";
    }
    file1.close();
}

int main() {
    setlocale(LC_ALL, "RU");

    string f;
    char ad;
    getline(cin, f);
    int d;
    int p;

    for (int i = 0; i < f.length(); ++i) {
        push(n, f[i], i);
    }


    cout << "Сформированная структура:\n";
    print(n);

    cout << "Введите количество элементов которые хотите добавить\n";
    cin >> d;
    cout << "Введите позицию на которую хотите добавить элементы\n";
    cin >> p;
    cout << "Введите элементы которые хотите добавить\n";
    cin.ignore();
    getline(cin, f);
    for (int i = 0; i < d; i++) {
        push(n, f[i], p + i);
    }
    print(n);


    cout << "Введите количество элементов которые хотите удалить\n";
    cin >> d;
    cout << "Введите позицию с которой хотите удалить элементы\n";
    cin >> p;
    for (int i = 0; i < d; i++) {
        del(n, p);
    }
    print(n);

    cout << "Введите элемент, поиск, которого необходимо выполнить\n";
    cin >> ad;
    if (search(n, ad) == 1) {
        cout << "Данный элемент есть в структуре\n";
    }
    else {
        cout << "Данного элемента нет в структуре\n";
    }

    saver(n);
    cout << "Структура сохранена в файл\n";
    killer(n);
    cout << "Cтруктура удалена\n";
    print(n);

    load(n);
    cout << "Структура загружена из файла\n";
    print(n);

    return 0;
}
