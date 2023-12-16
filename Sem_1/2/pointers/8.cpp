#include <iostream>
#include <string>

using namespace std;

int main() {

	string s, a, b;

	cin >> s >> a >> b;

	int lc = 0;
	int uc = 0;
	int other = 0;
	int l = s.length();

	for (int i = 0; i < l; i++) {

		string sim = s.substr(i, 1);

		if (sim == a)
			uc++;
		else if (sim == b)
			lc++;
		else
			other++;
	}

	cout << uc << endl << lc << endl << other << endl << l;

	return 0;
}