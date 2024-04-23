#include "Magazin.h"
Magazin::Magazin() {
	page_count = 0;
};
Magazin::Magazin(int p) {
	page_count = p;
}
Magazin::Magazin(const Magazin& m) {
	page_count = m.page_count;
}
Magazin::~Magazin(){}
void Magazin::Set_page_count(int p) {
	page_count = p;
}
int Magazin::Get_page_count() {
	return page_count;
}
Magazin& Magazin::operator=(const Magazin& m) {
	if (&m == this) {
		return *this;
	}
	page_count = m.page_count;
	return *this;
}
void Magazin::Show() {
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPage_count: " << page_count << endl;
}
void Magazin::Input() {
	cout << "\nName: "; cin >> name;
	cout << "\nAuthor: "; cin >> author;
	cout << "\nPage_count: "; cin >> page_count;
}