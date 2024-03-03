#include <iostream>
#include <string>
#include<fstream>

using namespace std;
ofstream f1("E:\\lab\\F.txt");

struct goverment {
	string name;
	string language;
	string state_currency;
	double currency_rate;


}state[193];


int form() {
	int c;
	if (f1) {
		cout << "¬ведите количество элементов: ";
		cin >> c;
		cout << endl;
		for (int i = 0; i < c; i++) {

			f1 << "State " << i + 1 << ": " << endl;
			cout << "¬ведите название " << i + 1 << " государства" << endl;
			cin >> state[i].name;
			f1 << "Name: " << '\t' << '\t' << state[i].name << endl;
			cout << endl;

			cout << "¬ведите €зык этого госудратсва" << endl;
			cin >> state[i].language;
			f1 << "Language: " << '\t' << state[i].language << endl;
			cout << endl;

			cout << "¬ведите валюту этого государства" << endl;
			cin >> state[i].state_currency;
			f1 << "State currency:" << '\t' << state[i].state_currency << endl;
			cout << endl;

			cout << "¬ведите курс этой валюты относительно $" << endl;
			cin >> state[i].currency_rate;
			f1 << "Currency rate:" << '\t' << state[i].currency_rate << endl << endl;
			cout << endl;

			cout << "====================================================" << endl;
		}

	}
	else {
		cout << "‘айл не открылс€";
	}

	return c;

}

void print(int c) {
	for (int i = 0; i < c; i++) {

		cout << "State " << i + 1 << ": " << endl;
		cout << endl;

		cout << "Name: " << '\t' << '\t' << state[i].name << endl;
		cout << endl;



		cout << "Language: " << '\t' << state[i].language << endl;
		cout << endl;


		cout << "State currency:" << '\t' << state[i].state_currency << endl;
		cout << endl;


		cout << "Currency rate:" << '\t' << state[i].currency_rate << endl << endl;
		cout << endl;

	}
	cout << "====================================================" << endl;

}

int add(int n) {
	int c;
	cout << endl;

	cout << "¬ведите количество элементов, которые хотите добавить: " << endl;
	cin >> c;
	cout << endl;
	for (int i = n; i < c + n; i++) {

		f1 << "State " << i + 1 << ": " << endl;
		cout << "¬ведите название " << i + 1 << " государства" << endl;
		cin >> state[i].name;
		f1 << "Name: " << '\t' << '\t' << state[i].name << endl;
		cout << endl;

		cout << "¬ведите €зык этого госудратсва" << endl;
		cin >> state[i].language;
		f1 << "Language: " << '\t' << state[i].language << endl;
		cout << endl;

		cout << "¬ведите валюту этого государства" << endl;	
		cin >> state[i].state_currency;
		f1 << "State currency:" << '\t' << state[i].state_currency << endl;
		cout << endl;

		cout << "¬ведите курс этой валюты относительно $" << endl;
		cin >> state[i].currency_rate;
		f1 << "Currency rate:" << '\t' << state[i].currency_rate << endl << endl;
		cout << endl;

		cout << "====================================================" << endl;
	}


	return c + n;
}


int del(int n) {
	f1.close();

	ofstream f3("E:\\lab\\F.txt");
	string na;


	cout << endl;

	if (f3) {

		cout << "¬ведите название государства, которое хотите удалить: " << endl;

		cin >> na;

		cout << endl;

		for (int i = 0; i < n; i++) {
			if (state[i].name == na) {
				for (int j = i; j < n; j++) {
					state[j] = state[j + 1];
				}
				n--;
			}
		}


		for (int i = 0; i < n; i++) {
			f3 << "State " << i + 1 << ": " << endl;

			f3 << "Name: " << '\t' << '\t' << state[i].name << endl;

			f3 << "Language: " << '\t' << state[i].language << endl;

			f3 << "State currency:" << '\t' << state[i].state_currency << endl;

			f3 << "Currency rate:" << '\t' << state[i].currency_rate << endl << endl;

		}
	}
	else {
		cout << "файл не открылс€";
	}

	f3.close();

	return(n);
}




int main() {
	setlocale(LC_ALL, "RU");

	int a, n = 0, d;

	n = form();
	print(n);

	cout << "’отите ли вы добавить еще элемент? (1 - да, 0 - нет)" << endl;
	cin >> a;

	while (a == 1) {
		n = add(n);
		print(n);

		cout << "’отите ли вы добавить еще элемент? (1 - да, 0 - нет)" << endl;
		cin >> a;
	}

	cout << endl << "’отите ли вы удалить элемет (1 - да, 0 - нет)" << endl;
	cin >> d;

	while (d == 1) {
		n = del(n);
		print(n);

		cout << "’отите ли вы удалить ещЄ элемент (1 - да, 0 - нет)" << endl;
		cin >> d;
	}

	f1.close();



	return 0;
}
