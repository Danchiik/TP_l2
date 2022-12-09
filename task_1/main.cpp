#include <iostream>
#include "Keeper.h"
/*
1. Стандартные потоки
Определить класс с именем WORKER, содержащий следующие поля:
● ФИО работника;
● название занимаемой должности;
● год поступления на работу.
Определить методы доступа к этим полям и перегруженные операции
извлечения и вставки для объектов типа WORKER.
Заранее число объектов не известно.
Написать программу, выполняющую следующие действия:
● записи должны быть размещены в алфавитном порядке;
● вывод на дисплей фамилий работников, чей стаж работы в
организации превышает значение, введенное с клавиатуры;
● если таких работников нет, вывести на дисплей соответствующее
сообщение.


*/

using namespace std;

void menuList()
{
	printf("main menu\n");
	printf("-1 exit\n");
	printf("0 see menu\n");
	printf("1 print to screen\n");
	printf("2 add\n");
	printf("3 edit\n");
	printf("4 remove\n");
	printf("5 search\n");
}

int menu()
{
	menuList();
	Keeper keep;

	int c = 0;
	while (1)
	{
		printf("\n\tmain menu\n");
		takeInt(&c);
		switch (c)
		{
		case -1:
			return 0;
		case 0:
			menuList();
			break;
		case 1:
			try {
				keep.printAll();
				}
				catch (string e)
				{
					cout << "exeption: " << e << endl;
				}
			break;
		case 2:
			keep.add();
			break;
		case 3:
			try {
			keep.edit();
				}
				catch (string e)
				{
					cout << "exeption: " << e << endl;
				}
			break;
		case 4:
			try {
			keep.remove();
				}
				catch (string e)
				{
					cout << "exeption: " << e << endl;
				}
			break;
		case 5:
			try {
				keep.search();
			}
			catch (string e)
			{
				cout << "exeption: " << e << endl;
			}
			break;
		default:
			printf("unknwon command inputed\nenter 0 to see menu\n");
		}
	}

	return -1;
}


int main(void)
{
	menu();
	return 0;
}