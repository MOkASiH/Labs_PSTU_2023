#include <iostream>
using namespace std;

int main() {

	int const n = 100;
	int arr[n][n] = { 0 };
	int c, k = 1;
	cin >> c;
	cout << endl;

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++) {
			if ((i + j) % 2 == 0) {
				arr[i][j] = k;
				k++;
			}
			if (k == 10) {
				k = 1;
			}
			cout << arr[i][j] << "  ";
		}
		cout << endl << endl;
	}


	return 0;
}
/*
1)
����:
10

�����:
1  0  2  0  3  0  4  0  5  0

0  6  0  7  0  8  0  9  0  1

2  0  3  0  4  0  5  0  6  0

0  7  0  8  0  9  0  1  0  2

3  0  4  0  5  0  6  0  7  0

0  8  0  9  0  1  0  2  0  3

4  0  5  0  6  0  7  0  8  0

0  9  0  1  0  2  0  3  0  4

5  0  6  0  7  0  8  0  9  0

0  1  0  2  0  3  0  4  0  5


2)
����:
5

�����:
1  0  2  0  3

0  4  0  5  0

6  0  7  0  8

0  9  0  1  0

2  0  3  0  4

3)
����:
30

�����:
1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0

0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3

4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0

0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6

7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0

0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9

1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0

0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3

4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0

0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6

7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0

0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9

1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0

0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3

4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0

0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6

7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0

0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9

1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0

0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3

4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0

0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6

7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0

0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9

1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0

0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3

4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0

0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6

7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0

0  4  0  5  0  6  0  7  0  8  0  9  0  1  0  2  0  3  0  4  0  5  0  6  0  7  0  8  0  9






*/