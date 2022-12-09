#pragma once

#include "Worker.h"
class Keeper
{
	int size;
	Worker** list;

	void del(int);
	void operator+(Worker*);

	void sort();

public:

	Keeper();

	~Keeper();

	int add();
	void edit();
	void remove();

	void printAll();

	void search();

};