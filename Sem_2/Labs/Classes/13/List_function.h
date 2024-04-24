#pragma once
#include<iostream>
#include <list>
#include <numeric>
#include <algorithm>

using namespace std;

void Show_list(const list<Pair>& m_list) {
	if (m_list.size() > 0) {
		for_each(m_list.begin(), m_list.end(), [](Pair p) {
			cout << p << '\n';
			});
	}
	else {
		cout << "Список пуст!";
	}
	cout << '\n';
}
