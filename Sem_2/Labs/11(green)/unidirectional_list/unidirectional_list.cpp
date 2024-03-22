#include <iostream>
#include <string>
#include<fstream>
using namespace std;

struct node {
    char data;
    node* next = nullptr;

};

struct list {
    node* head = nullptr;
    int size = 0;
}n;

void pushBack(list& list, char& data) {
    node* new_node = new node;
    new_node->data = data;
    if (list.head == nullptr) {
        list.head = new_node;
    }
    else {
        node* cur_node = list.head;

        while (cur_node->next != nullptr) {
            cur_node = cur_node->next;
        }
        cur_node->next = new_node;
    }
    list.size++;
}

void push(list& list, char& data, int d) {
    node* pre_node = nullptr;
    node* cur_node = list.head;
    node* new_node = new node;
    new_node->data = data;
    if (d == 1) {
        new_node->next = list.head;

        list.head = new_node;
        list.size++;
        return;
    }
    for (int i = 0; i < d - 1; i++) {
        if (i == d - 2) {
            pre_node = cur_node;
        }
        cur_node = cur_node->next;
    }
    pre_node->next = new_node;
    new_node->next = cur_node;
    list.size++;
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

        list.head = list.head->next;

        delete remove;
        list.size--;
        return;
    }

    node* pre_node = nullptr;

    for (int i = 0; i < d - 1; i++) {
        if (i == d - 2) {
            pre_node = cur_node;
        }
        cur_node = cur_node->next;
    }

    pre_node->next = cur_node->next;

    node* remove = cur_node;

    delete remove;
    list.size--;
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
    file1.close();
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
    list.size = 0;
}

void load(list& list) {
    ifstream file1("C:\\Users\\MOkASiH\\Desktop\\sem_2\\11\\save.txt");
    string f;
    cin.ignore();

    if (file1) {
        getline(file1, f);
        for (int i = 0; i < f.length(); ++i) {
            pushBack(n, f[i]);
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

    for (int i = 0; i < f.length(); ++i) {
        pushBack(n, f[i]);
    }

    node* cur_node = n.head;

    cout << "Сформированная структура:\n";

    print(n);
    cout << "Введите позицию на которую хотите добавить символ\n";
    cin >> d;
    cout << "Введите cимвол, который хотите добавить\n";
    cin >> ad;
    push(n, ad, d);
    print(n);


    cout << "Введите позицию символа который хотите удалить\n";
    cin >> d;
    del(n, d);
    print(n);

    int c;
    cout << "Введите количетсво элементов которые хотите добавить\n";
    cin >> c;
    cout << "Введите позицию с которой будут добавлены элементы\n";
    cin >> d;
    cout << "Введите элементы, которые хотите добавить\n";
    cin.ignore();
    getline(cin, f);
    for (int i = 0; i < c; ++i) {
        push(n, f[i], d + i);
    }
    print(n);

    cout << "Введите количество элементов, которые хотите удалить\n";
    cin >> c;
    cout << "Введите позицию с которой хотите удалить элементы\n";
    cin >> d;
    for (int i = 0; i < c; ++i) {
        del(n, d);
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
