#pragma once
#include "Person.h"

class Student : public Person {
private:
	string subject;
	int mark;
public:
	Student();
	Student(string, int, string, int);
	Student(const Student&);
	~Student(){}

	string get_subject() { return subject; }
	int get_mark() { return mark; }

	void set_subject(string s) { subject = s; }
	void set_mark(int m) { mark = m; }

	Student& operator=(const Student&);

	friend istream& operator >>(istream& in, Student& p);
	friend ostream& operator <<(ostream& out, const Student& p);

	void Show();
	
};