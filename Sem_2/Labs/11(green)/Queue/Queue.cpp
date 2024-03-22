#include<iostream>
#include<string>
#include<fstream>

using namespace std;

struct Queue {
    char data;
    Queue* next = nullptr;
};
struct que {
    Queue* front = nullptr;
    Queue* back = nullptr;
    int size;
    void push(char data) {
        Queue* new_node = new Queue;
        new_node->data = data;
        new_node->next = nullptr;
        if (size == 0) {
            front = new_node;
            back = new_node;
        }
        else {
            back->next = new_node;
            back = new_node;
        }
        size++;
    }
    char pop() {
        char datatmp = front->data;
        Queue* tmp = front;
        if (size == 1) {
            back = nullptr;
        }
        front = front->next;
        size--;
        delete tmp;
        return datatmp;
    }
}s;


void print(que& s) {
    if (s.size == 0) {
        cout << "������� �����." << endl;
        return;
    }
    char datatmp;
    int size = s.size;
    for (int i = 0; i < size; i++) {
        datatmp = s.pop();
        cout << datatmp;
        s.push(datatmp);

    }

}

void add(que& s, char data, int n) {
    que tmp;
    char datatmp;
    int size = s.size;
    for (int i = 0; i < size; i++) {
        datatmp = s.pop();
        if (i == n - 1) {
            s.push(data);
        }
        s.push(datatmp);
    }
}

void del(que& s, int n) {
    char datatmp;
    int size = s.size;
    for (int i = 0; i < size; i++) {
        datatmp = s.pop();
        if (i != n - 1) {
            s.push(datatmp);
        }
    }
}

bool search(que& s, char da) {
    char datatmp;
    bool flag = false;
    int size = s.size;
    for (int i = 0; i < size; i++) {
        datatmp = s.pop();
        if (datatmp == da) {
            flag = true;
        }
        s.push(datatmp);
    }

    return flag;
}

void saver(que& s) {
    ofstream file1("C:\\Users\\MOkASiH\\Desktop\\sem_2\\11\\save.txt");
    if (file1) {
        char datatmp;
        int size = s.size;
        for (int i = 0; i < size; i++) {
            datatmp = s.pop();
            file1 << datatmp;
            s.push(datatmp);
        }
    }

    else {
        cout << "���� �� ��������";
    }
    file1.close();
}

void killer(que& s) {
    int size = s.size;
    for (int i = 0; i < size; i++) {
        s.pop();
    }
}

void load(que& s) {
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
        cout << "���� �� ������";
    }
}




int main() {
    setlocale(LC_ALL, "RU");
    int p, d;
    char ad;
    string f;
    cout << "������� ������� �������� ������ ��������� �������\n";
    getline(cin, f);
    for (int i = 0; i < f.length(); i++)
    {
        s.push(f[i]);
    }

    cout << "�������������� �������\n";
    print(s);

    cout << "\n������� ���������� ��������� ������� ������ ��������\n";
    cin >> d;
    cout << "������� ������� �� ������� ������ �������� ��������\n";
    cin >> p;
    cout << "������� �������� ������� ������ ��������\n";
    cin.ignore();
    getline(cin, f);
    for (int i = 0; i < d; i++) {
        add(s, f[i], p + i);
    }
    print(s);

    cout << "\n������� ���������� ��������� ������� ������ �������\n";
    cin >> d;
    cout << "������� ������� � ������� ������ ������� ��������\n";
    cin >> p;
    for (int i = 0; i < d; i++) {
        del(s, p);
    }
    print(s);


    cout << "\n������� �������, �����, �������� ���������� ���������\n";
    cin >> ad;
    if (search(s, ad) == 1) {
        cout << "������ ������� ���� � ���������\n";
    }
    else {
        cout << "������� �������� ��� � ���������\n";
    }

    saver(s);
    cout << "��������� ��������� � ����\n";
    killer(s);
    cout << "C�������� �������\n";
    print(s);

    load(s);
    cout << "��������� ��������� �� �����\n";
    print(s);

    return 0;
}