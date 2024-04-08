#include<iostream>
#include<string>

#include<time.h>

using namespace std;

string rand_name[30] = { "Иван", "Андрей", "Антон", "Амин", "Роберт", "Георгий", "Борис", "Владислав", "Дмитрий", "Никита", "Данила", "Артем", "Парвиз", "Сергей", "Илья", "Григорий", "Артур", "Денис", "Алексей", "Александр", "Валерий", "Дамир", "Михаил", "Константин", "Николай", "Герман", "Иннокентий", "Богдан", "Станислав", "Сурман" };


int get_hash(int size, string str) {
	unsigned key = 0;
	for (int i = 0; i < str.size(); i++) {
		key += str[i];
	}
	return static_cast<int>(key * 0.2) % size;
}

struct node {
	string name = " ";
	int series;
	int number;
	int node_size = 0;
	node* next = nullptr;
	node* prev = nullptr;
};

struct open_address {
	const int size = 50;
	node* table = new node[size];

	void set_node(string name, int series, int  number) {
		int hash = get_hash(size, name);
		while (table[hash % size].name != " ") {
			if (++hash - size == size) {
				break;
			}
		}
		if (hash - size < size) {
			table[hash % size].name = name;
			table[hash % size].series = series;
			table[hash % size].number = number;
		}
	}
	void print_table() {
		for (int i = 0; i < size; i++) {
			if (table[i].name != " ") {
				cout << "Name: " << table[i].name << endl;
				cout << "Series: " << table[i].series << endl;
				cout << "Number: " << table[i].number << endl;
				cout << "=======================\n";
			}
		}
	}
	void set_table(int count) {
		srand(time(0));
		for (int i = 0; i < count; i++) {
			int r = rand() % 30;
			int series = rand() % 8999 + 1000;
			int number = rand() % 899999 + 100000;
			set_node(rand_name[r], series, number);
		}
	}
};

struct chain {
	const int size = 50;
	node* table = new node[size];

	void set_node(string name, int series, int  number) {
		int hash = get_hash(size, name);
		if (table[hash].name == " ") {
			table[hash].name = name;
			table[hash].series = series;
			table[hash].number = number;
			table[hash].node_size++;
		}
		else {
			node* new_node = new node;
			new_node->name = name;
			new_node->series = series;
			new_node->number = number;
			node* tmp = &table[hash];
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new_node;
			new_node->prev = tmp;
			table[hash].node_size++;
		}
	}
	void print_table() {
		for (int i = 0; i < size; i++) {
			if (table[i].name != " ") {
				node* tmp = &table[i];
				while (tmp->next != nullptr) {
					cout << "Name: " << table[i].name << endl;
					cout << "Series: " << table[i].series << endl;
					cout << "Number: " << table[i].number << endl;
					cout << "=======================\n";
					tmp = tmp->next;
				}
			}
		}
	}
	void set_table(int count) {
		srand(time(0));
		for (int i = 0; i < count; i++) {
			int r = rand() % 30;
			int series = rand() % 8999 + 1000;
			int number = rand() % 899999 + 100000;
			set_node(rand_name[r], series, number);
		}
	}
};




int main() {
	system("chcp 1251>0");

	int method;


	cout << "Какой способ устранения коллизий использовать\n";
	cout << "1. Метод цепочек\n";
	cout << "2. Открытая адресация\n";
	cin >> method;
	if (method == 1) {
		chain* people = new chain;
		people->set_table(80);
		people->print_table();
	}
	else if (method == 2) {
		open_address* people = new open_address;
		people->set_table(80);
		people->print_table();
	}
	else {
		cout << "Нет";
	}

	return 0;
}
