#define _CRT_SECURE_NO_WARNINGS
#include "Keeper.h"

#include "Worker.h"
#include "helper.h"


Keeper::Keeper()
{
	printf("Keeper() constructor called\n");
	size = 0;
	list = nullptr;
	
}

Keeper::~Keeper()
{
	printf("Keeper() destructor called\n");
	for (int i = 0; i < size; i++)
		delete list[i];
	size = 0;
}

void Keeper::sort()
{
	if (size == 0)
		return;

	if (size == 1)
		return;

	for (int i = 0; i < size - 1; )
	{

		if (list[i]->getFio() > list[i + 1]->getFio())
		{
			// поменять местами
			Worker* temp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = temp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
}


void Keeper::printAll()
{
	printf("All list items:\n");
	if (size == 0)
		throw (string)"none found";
	sort();
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << " " << *list[i] << endl;
	}
	
}

void Keeper::operator+(Worker* obj)
{
	size += 1;
	Worker** created = new Worker * [size];
	for (int i = 0; i < size - 1; i++)
	{
		created[i] = list[i];
	}

	created[size - 1] = obj;
	list = created;
}

int Keeper::add()
{
	Worker* new_Worker = new Worker;

	*this + new_Worker;

	return 0;
}


void Keeper::edit()
{
	if (size == 0)
	{
		throw (string)"list is empty";
	}

	int c = 0;

	while (1)
	{
		printf("edit keeper menu\n-1 back\n1 - %d edit\n", size);
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		default:
			if (c < 1 || c > size)
				printf("invalid input\n");
			else
				list[c - 1]->edit();

		}
	}
}

void Keeper::del(int id)
{
	delete list[id];
	for (int i = id; i < size - 1; i++)
	{
		list[i] = list[i + 1];
	}
	size--;
}

void Keeper::remove()
{
	if (size == 0)
	{
		throw (string)"list is empty";
	}

	int c = 0;

	while (1)
	{
		printf("remove keeper menu\n-1 back\n1 - %d remove\n", size);
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		default:
			if (c < 1 || c > size)
				printf("invalid input\n");
			else
			{
				del(c - 1);
				printf("removed\n");
				if (size == 0)
					return;
			}

		}
	}
}

void Keeper::search()
{
	if( size == 0)
		throw (string)"list is empty";

	int yearSearch = -1;
	cout << "enter years of work: ";
	while( yearSearch<= 0)
		takeInt(&yearSearch);

	int count = 0; 
	for (int i = 0; i < size; i++)
	{
		int stazh = 2022 - list[i]->getYear();
		if (stazh >= yearSearch)
		{
			cout << *list[i] << endl;
			count++;
		}
	}
	if (count == 0)
	{
		cout << "none found" << endl;
	}
}