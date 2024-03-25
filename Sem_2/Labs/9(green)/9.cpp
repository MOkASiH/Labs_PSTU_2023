#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");

    ifstream file1("C:\\Users\\MOkASiH\\Desktop\\Infa\\F1.txt");
    ofstream file2("C:\\Users\\MOkASiH\\Desktop\\Infa\\F2.txt");

    string line;
    int punct[500] = { 0 };
    int st = 0;

    while (getline(file1, line)) {

        string words;
        stringstream ss;
        int c = 0, p = 0;
        ss << line;
        bool flag = false;

        for (int i = line.length(); i > 0; i--) {
            if (line[i] == '?' or line[i] == ',' or line[i] == '.' or line[i] == '!') {
                line[i] = ' ';
                punct[i] = i;
            }
        }


        while (ss >> words) {
            for (int i = words.length(); i > 0; i--) {
                if (words[i] == '?' or words[i] == ',' or words[i] == '.' or words[i] == '!') {
                    words[i] = ' ';
                }
            }
            for (int i = 0; (i = line.find(words, i)) != line.npos; i++) {
                c++;
                if (c > 1) {
                    flag = true;
                    break;
                }
            }
            c = 0;
        }


        if (flag == true) {
            punct[st] = 550;
        }


        st++;
    }

    file1.close();

    ifstream file3("C:\\Users\\MOkASiH\\Desktop\\Infa\\F1.txt");
    string line1;
    int k = 0;

    while (getline(file3, line1)) {
        if (punct[k] == 550) {
            file2 << line1 << endl;
        }
        k++;
    }
    file2.close();
    file3.close();



    ifstream file4("C:\\Users\\MOkASiH\\Desktop\\Infa\\F2.txt");
    string line3;

    char vowel[20] = { 'а','о','у','ы','э','е', 'ё','и','ю','я', 'А','О','У','Ы','Э','Е', 'Ё','И','Ю','Я' };
    int v = 0;

    while (getline(file4, line3)) {
        for (int i = 0; i < line3.length(); i++) {
            for (int j = 0; j < 20; j++) {
                if (line3[i] == vowel[j]) {
                    v++;
                }
            }
        }
    }
    cout << v;


    return 0;
}
