#pragma once
#include <iostream>

using namespace std;

class Worker
{
	string FIO;
	string job_title;
	int year;

public:

	Worker()
	{
		cout << "Worker constructor" << endl;
	}

	void setFio(string str)
	{
		FIO = str;
	}

	void setJob(string str)
	{
		job_title = str;
	}

	void setYear(int y)
	{
		year = y;
	}

	string getFio()
	{
		return FIO;
	}

	string getJob()
	{
		return job_title;
	}

	int getYear()
	{
		return year;
	}

};