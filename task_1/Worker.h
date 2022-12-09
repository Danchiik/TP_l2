#pragma once
#include <iostream>
#include <string>
#include "helper.h"

using namespace std;

class Worker
{
	string fio;
	string job;
	int year;

public:

	Worker();

	void setFio(string str);

	void setJob(string str);

	void setYear(int y);

	string getFio();

	string getJob();

	int getYear();



	friend std::istream& operator>>(std::istream& in, Worker& w);

	friend std::ostream& operator<<(std::ostream& os, Worker& w);

	void edit();

};