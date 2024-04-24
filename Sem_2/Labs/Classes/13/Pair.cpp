#include "Pair.h"

Pair::Pair() {
	first = 0;
	second = 0.0;
}
Pair::Pair(int f, double s) {
	first = f;
	second = s;
}
Pair::Pair(const Pair& p) {
	first = p.first;
	second = p.second;
}
Pair::~Pair() {}
void Pair::set_first(int f) {
	first = f;
}
void Pair::set_double(double s) {
	second = s;
}
int Pair::get_first() {
	return first;
}
double Pair::get_double() {
	return second;
}
Pair& Pair::operator+(const Pair& p) {
	first += p.first;
	second += p.second;
	return *this;
}
ostream& operator<<(ostream& out, const Pair& p) {
	return (out << p.first << " : " << p.second);
}
istream& operator>>(istream& in, Pair& p) {
	in >> p.first;
	in >> p.second;
	return in;
}