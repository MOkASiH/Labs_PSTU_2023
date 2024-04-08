#pragma once
#include<iostream>

using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	virtual ~Person(void);
	string get_name() { return name; };
	int get_age() { return age; }

	void set_name(string);
	void set_age(int);

	Person& operator=(const Person&);

	friend istream& operator >>(istream& in, Person& p);
	friend ostream& operator <<(ostream& out, const Person& p);


};