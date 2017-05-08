#include <iostream>
#include "ball.h"

using namespace std;

int promprt_menu_item()
{
	int item;
	cout <<"выберите вариант:" << endl;
	cout <<"0. Выход " << endl
		<< "1. создание окружности" << endl
		<< "2. перемещение окружности на плоскости" << endl
		<< "3. маштабирование окружности" << endl
		<< "4. вычисление площади поверхности, ограниченной окружностью" << endl
		<< "5. удаление окружности" << endl;
	cout << ">>> ";
	cin >> item;
	
	return item;
};

int main(int argc, char* argv[])
{
	promprt_menu_item();

	return 0;
};
