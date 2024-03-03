#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int line;

	cout << "¬ведите количество строк в тексте: ";
	cin >> line;
	cin.ignore();


	string* text = new string[line];

	for (int i = 0; i < line; ++i) {
		getline(cin, text[i]);
	}

	cout << endl << endl;

	for (int i = 0; i < line; i++) {
		string temp = text[i];
		int l = temp.length();
		if (tolower(text[i][0]) == tolower(text[i][l - 1])) {
			for (int j = i; j < line - 1; j++) {
				text[j] = text[j + 1];
			}
			line--;
		}
	}


	cout << "—троки начинающиес€ на одну и ту же букву были удалены" << endl << endl;

	for (int i = 0; i < line; i++) {
		cout << text[i] << endl;
	}


	delete[] text;


	return 0;
}
