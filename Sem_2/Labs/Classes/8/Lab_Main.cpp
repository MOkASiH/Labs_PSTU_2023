﻿#include<iostream>
#include <string>
#include"Print.h"
#include"Object.h"
#include"Magazin.h"
#include"Dialog.h"

using namespace std;

int main() {
	system("chcp 1251 > NULL");
	
	cout << "m: Создать группу\n+: Добавить элемент\n-: Удалить элимент\ns: Информация о элементах\nz: Информация (Названия)\nq: Выход\n";
	Dialog D;
	D.Execute();

	return 0;
}