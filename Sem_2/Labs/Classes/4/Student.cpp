#include"Student.h"

Student::Student():Person(){
	subject = "";
	mark = 0;
}
Student::Student(string n, int a, string s, int m):Person(n,a) {
	subject = s;
	mark = m;
}
Student::Student(const Student& s) {
	name = s.name;
	age = s.age;
	subject = s.subject;
	mark = s.mark;
}

Student& Student::operator=(const Student& s) {
	if (&s == this) {
		return* this;
	}
	name = s.name;
	age = s.age;
	subject = s.subject;
	mark = s.mark;
	return *this;
}

istream& operator >>(istream& in, Student& p) {
	cout << "name: "; in >> p.name;
	cout << "age: "; in >> p.age;
	cout << "subject: "; in >> p.subject;
	cout << "mark: "; in >> p.mark;
	return in;
}
ostream& operator <<(ostream& out, const Student& p) {
	out << "\nname: " << p.name;
	out << "\nage: " << p.age <<" y.o.";
	out << "\nsubject: " << p.subject;
	out << "\nmark: " << p.mark;
	if (p.mark <= 2) {
	out << "\nНа кол двоечника";
	}
	return out;
}
