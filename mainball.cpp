#include <iostream>
#include <iomanip>
#include  <Windows.h>
#include "ball.h"

using namespace std;
//Составить описание класса для создания шаров. Предусмотреть методы для создания 
//и уничтожения объектов, перемещения в трёхмерном пространстве, масштабирования и 
//вычисления объёма, ограниченного объектом. 
int prompt_mainball_item()
{
	int item;
	cout <<"выберите вариант:" << endl;
	cout <<"0. Выход " << endl
		<< "1. создание шара" << endl
		<< "2. перемещение шара на плоскости" << endl
		<< "3. маштабирование " << endl
		<< "4. вычисление объёма шара" << endl
		<< "5. удаление шара" << endl;
	cout << ">>> ";
	cin >> item;
	
	return item;
};

int main(int argc, char* argv[])
{	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Ball* ball = NULL;



	for (;;)
	{
		int item = prompt_mainball_item(); 

		if (item == 0)
		{
			return 0;
		}
		else if (item == 1)
		{
			if (ball == NULL)
			{
				double x, y, z, r;
				cout << "Введите координаты центра шара (x y z через пробел): ";
				cin >> x >> y >> z;
				cout << "Введите радиус шара: ";
				cin >> r;

				if (r >= 0)
				{
					ball = new Ball(x, y, z, r);

					cout << endl << "Успешно создан шар радиусом " << ball->getRadius() << " и координатами центра (" << ball->getCenterX() << ", " << ball->getCenterY() << ", " << ball->getCenterZ() <<")" << endl;
				}
				else
				{
					cout << "Радиус должен быть неотрицательным!" << endl;
				}
			}
			else
			{
				cout << "Сначала удалите существующий шар" << endl;
			}
		}
		else if (item == 2)
		{
			if (ball == NULL)
			{
				cout << "Окружность ещё не создана" << endl;
			}
			else
			{
				double dx, dy, dz;
				cout << "Введите координаты вектора смещения (x y z через пробел): ";
				cin	 >> dx >> dy >> dz;

				ball->move(dx, dy, dz);

				cout << endl << "Перемещенная окружность имеет радиус " << ball->getRadius() << " и координаты центра (" << ball->getCenterX() << ", " << ball->getCenterY() << ", " << ball->getCenterZ() <<  ")" << endl;                                                                                  
			}
		}
		else if (item == 3)
		{
			if (ball == NULL)
			{
				cout << "шар ещё не создана" << endl;
			}
			else
			{
				double k;
				cout << "Введите коэффициент масштабирования: ";
				cin	 >> k;

				ball->scale(k);

				cout << endl << "Масштабированный шар имеет радиус " << ball->getRadius() << " и координаты центра (" << ball->getCenterX() << ", " << ball->getCenterY() << ")" << endl;
			}
		}
		else if (item == 4)
		{
			if (ball == NULL)
			{
				cout << "шар ещё не создана" << endl;
			}
			else
			{
				cout << "Объём шара равен " << setprecision(14) << ball->calculateArea() << endl;
			}
		}
		else if (item == 5)
		{
			if (ball == NULL)
			{
				cout << "шар ещё не создана" << endl;
			}
			else
			{
				delete(ball);
				ball = NULL;

				cout << "шар успешно удалена" << endl;
			}
		}
		
		else
		{
			cout << "Вы выбрали неверный вариант. Попробуйте ещё раз." << endl;
		}

		cout << endl;
	}

return 0;
}
