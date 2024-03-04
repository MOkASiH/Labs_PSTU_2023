#include <iostream>
#include <string>

using namespace std;

int main() {
	setlocale(LC_ALL, "RU");

	int line;

	cout << "Ââåäèòå êîëè÷åñòâî ñòðîê â òåêñòå: ";
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
			i--;
		}
	}


	cout << "Ñòðîêè íà÷èíàþùèåñÿ íà îäíó è òó æå áóêâó áûëè óäàëåíû" << endl << endl;

	for (int i = 0; i < line; i++) {
		cout << text[i] << endl;
	}


	delete[] text;


	return 0;
}
