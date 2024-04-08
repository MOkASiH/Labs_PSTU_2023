#pragma once
#include "Object.h"

class Vector {
private:
	Object** beg;
	int size;
	int cur;
public:
	Vector();
	Vector(int);
	~Vector();
	void Add(Object*);
	friend ostream& operator<<(ostream& out, const Vector& v);
};