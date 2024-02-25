#include <iostream>
#include <ctime>

using namespace std;

int board[8][8];
const int queen = -1;
int s, f;

void resetboard();
void showboard();
bool checkqueen(int i);
void deletequeen(int i, int j);
void setqueen(int i, int j);

void resetboard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			board[i][j] = 0;
		}
	}
	board[s][f] = queen;
}
void showboard() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == queen) {
				cout << "[Q] ";
			}
			else {
				cout << "[ ] ";
			}
		}
		cout << endl << endl;
	}
}
void setqueen(int i, int j) {
	int d;


	for (int x = 0; x < 8; ++x) {
		board[x][j]++;
		board[i][x]++;

		d = j - i + x;

		if (d >= 0 && d < 8) {
			board[x][d]++;
		}

		d = j + i - x;

		if (d >= 0 && d < 8) {
			board[x][d]++;
		}
	}
	board[i][j] = queen;

}
void deletequeen(int i, int j) {

	int d;

	for (int x = 0; x < 8; ++x) {
		board[x][j]--;
		board[i][x]--;

		d = j - i + x;

		if (d >= 0 && d < 8) {
			board[x][d]--;
		}

		d = j + i - x;

		if (d >= 0 && d < 8) {
			board[x][d]--;
		}
	}
	board[i][j] = 0;
}

bool checkqueen(int i) {

	bool result = false;

	for (int j = 0; j < 8; ++j) {
		if (board[i][j] == 0) {
			setqueen(i, j);
			if (i == 7) {
				result = true;
			}
			else if (!(result = checkqueen(i + 1)))
			{
				deletequeen(i, j);
			}

		}
		if (result) {
			break;
		}
	}
	return result;
}
int main() {
	srand(time(0));


	s = rand() % 8;
	f = rand() % 8;

	resetboard();
	checkqueen(0);
	showboard();

	return 0;
}