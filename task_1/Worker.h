#pragma once
#include <iostream>

using namespace std;

class Worker
{
	string fio;
	string job;
	int year;

public:

	Worker()
	{
		cout << "Worker constructor" << endl;
		fio = "unknown";
		job = "unknown";
		year = 1990;
	}

	void setFio(string str)
	{
		fio = str;
	}

	void setJob(string str)
	{
		job = str;
	}

	void setYear(int y)
	{
		year = y;
	}

	string getFio()
	{
		return fio;
	}

	string getJob()
	{
		return job;
	}

	int getYear()
	{
		return year;
	}



	friend std::ostream& operator<<(std::ostream& os,  Worker& w)
	{
		return os << w.getFio() << " " << w.getJob() << " works since:" << w.getYear();
	}

};