#include "Person.h"

Person::Person(void) {
	name = "";
	age = 0;
}
Person::Person(string n, int a) {
	name = n;
	age = a;
}
Person::Person(const Person& p) {
	name = p.name;
	age = p.age;
}
Person::~Person(){}
void Person::set_name(string n) {
	name = n;
}
void Person::set_age(int a) {
	age = a;
}

Person& Person::operator=(const Person& p) {
	if (this == &p) {
		return *this;
	}
	name = p.name;
	age = p.age;
	return *this;
}

istream& operator >>(istream& in, Person& p) {
	cout << "name: "; in >> p.name;
	cout << "age: "; in >> p.age;
	return in;
}
ostream& operator <<(ostream& out, const Person& p) {
	out << "\nname: " << p.name;
	out << "\nage: " << p.age << " y.o.";
	return out;
}