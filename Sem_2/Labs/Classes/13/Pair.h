#pragma once
#include <iostream>

using namespace std;
class Pair{
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair();
	void set_first(int);
	void set_double(double);
	int get_first();
	double get_double();
	Pair& operator+(const Pair&);
	friend ostream& operator<<(ostream& out, const Pair& p);
	friend istream& operator>>(istream& in, Pair& p);
};

