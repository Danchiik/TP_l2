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



	friend std::istream& operator>>(std::istream& in, Worker& w)
	{
		std::cout << "fio: ";
		in.clear();
		in.ignore();
		string str;
		getline(in, str);
		w.setFio(str);

		std::cout << "job title: ";
		in.clear();
		getline(in, str);
		w.setJob(str);

		std::cout << "year: ";
		in.clear();
		int y;
		takeInt(&y);
		w.setYear(y);

		in.sync();
		return in;
	}

	friend std::ostream& operator<<(std::ostream& os,  Worker& w)
	{
		return os << w.getFio() << " " << w.getJob() << " works since:" << w.getYear();
	}

	void edit()
	{
		cout << "now value is: ";
		cout << *this;

		int c;
		while (true)
		{
			printf("\n\tedit worker menu\n");
			printf("-1 back\n\t1 edit\n");
			takeInt(&c);
			switch (c)
			{
			case -1:
				return;

			case 1:
				printf("enter new  values\n");
				cin >> *this;
				break;

			default:
				printf("invalid input\n");

			}
		}
	}

};