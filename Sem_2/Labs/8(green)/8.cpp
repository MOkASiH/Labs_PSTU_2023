#include <iostream>
#include <string>
#include<fstream>

using namespace std;
ofstream f1("E:\\lab\\F.txt");

struct state {
	string name;
	string language;
	string state_currency;
	double currency_rate;


}gov[193];


int form() {
	int c;
	if (f1) {
		cout << "Введите количество элементов: ";
		cin >> c;
		cout << endl;
		for (int i = 0; i < c; i++) {

			f1 << "Goverment " << i + 1 << ": " << endl;
			cout << "Введите название " << i + 1 << " государства" << endl;
			cin >> gov[i].name;
			f1 << "Name: " << '\t' << '\t' << gov[i].name << endl;
			cout << endl;

			cout << "Введите язык этого госудратсва" << endl;
			cin >> gov[i].language;
			f1 << "Language: " << '\t' << gov[i].language << endl;
			cout << endl;

			cout << "Введите валюту этого государства" << endl;
			cin >> gov[i].state_currency;
			f1 << "State currency:" << '\t' << gov[i].state_currency << endl;
			cout << endl;

			cout << "Введите курс этой валюты относительно $" << endl;
			cin >> gov[i].currency_rate;
			f1 << "Currency rate:" << '\t' << gov[i].currency_rate << endl << endl;
			cout << endl;

			cout << "====================================================" << endl;
		}

	}
	else {
		cout << "Файл не открылся";
	}

	return c;

}

void print(int c) {
	for (int i = 0; i < c; i++) {

		cout << "Goverment " << i + 1 << ": " << endl;
		cout << endl;

		cout << "Name: " << '\t' << '\t' << gov[i].name << endl;
		cout << endl;



		cout << "Language: " << '\t' << gov[i].language << endl;
		cout << endl;


		cout << "State currency:" << '\t' << gov[i].state_currency << endl;
		cout << endl;


		cout << "Currency rate:" << '\t' << gov[i].currency_rate << endl << endl;
		cout << endl;

	}
	cout << "====================================================" << endl;

}

int add(int n) {
	int c;
	cout << endl;

	cout << "Введите количество элементов, которые хотите добавить: " << endl;
	cin >> c;
	cout << endl;
	for (int i = n; i < c + n; i++) {

		f1 << "Goverment " << i + 1 << ": " << endl;
		cout << "Введите название " << i + 1 << " государства" << endl;
		cin >> gov[i].name;
		f1 << "Name: " << '\t' << '\t' << gov[i].name << endl;
		cout << endl;

		cout << "Введите язык этого госудратсва" << endl;
		cin >> gov[i].language;
		f1 << "Language: " << '\t' << gov[i].language << endl;
		cout << endl;

		cout << "Введите валюту этого государства" << endl;
		cin >> gov[i].state_currency;
		f1 << "State currency:" << '\t' << gov[i].state_currency << endl;
		cout << endl;

		cout << "Введите курс этой валюты относительно $" << endl;
		cin >> gov[i].currency_rate;
		f1 << "Currency rate:" << '\t' << gov[i].currency_rate << endl << endl;
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

		cout << "Введите название государства, которое хотите удалить: " << endl;

		cin >> na;

		cout << endl;

		for (int i = 0; i < n; i++) {
			if (gov[i].name == na) {
				for (int j = i; j < n; j++) {
					gov[j] = gov[j + 1];
				}
				n--;
			}
		}


		for (int i = 0; i < n; i++) {
			f3 << "Goverment " << i + 1 << ": " << endl;

			f3 << "Name: " << '\t' << '\t' << gov[i].name << endl;

			f3 << "Language: " << '\t' << gov[i].language << endl;

			f3 << "State currency:" << '\t' << gov[i].state_currency << endl;

			f3 << "Currency rate:" << '\t' << gov[i].currency_rate << endl << endl;

		}
	}
	else {
		cout << "файл не открылся";
	}

	f3.close();

	return(n);
}




int main() {
	setlocale(LC_ALL, "RU");

	int a, n = 0, d;

	n = form();
	print(n);

	cout << "Хотите ли вы добавить еще элемент? (1 - да, 0 - нет)" << endl;
	cin >> a;

	while (a == 1) {
		n = add(n);
		print(n);

		cout << "Хотите ли вы добавить еще элемент? (1 - да, 0 - нет)" << endl;
		cin >> a;
	}

	cout << endl << "Хотите ли вы удалить элемет (1 - да, 0 - нет)" << endl;
	cin >> d;

	while (d == 1) {
		n = del(n);
		print(n);

		cout << "Хотите ли вы удалить ещё элемент (1 - да, 0 - нет)" << endl;
		cin >> d;
	}

	f1.close();



	return 0;
}
