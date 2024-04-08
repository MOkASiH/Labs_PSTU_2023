#include "Pair.h"

Pair& Pair::operator=(const Pair& p) {
	if (&p != this) {
		first = p.first;
		second = p.second;
	}
	return *this;
}
Pair Pair::operator-(const Pair& p) {
	Pair result(first - p.first, second - p.second);
	return result;
}
Pair& Pair::operator+(int f) {
	this->first += f;
	return *this;
}
Pair& Pair::operator+(double s) {
	this->second += s;
	return *this;
}
Pair& Pair::operator++() {
	first++;
	second++;
	return *this;
}
Pair Pair::operator++(int) {
	Pair tmp = *this;
	this->first++;
	this->second++;
	return tmp;
}

istream& operator >> (istream& in, Pair& p) {
	in >> p.first;
	in >> p.second;
	return in;
}
ostream& operator << (ostream& out, const Pair& p) {
	return out << p.first << "|| " << p.second;
}