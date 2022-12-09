#pragma once
#include <iostream>
#include <string>
#include "helper.h"
#include "Worker.h"

using namespace std;

Worker::Worker()
{
	cout << "Worker constructor" << endl;
	fio = "unknown";
	job = "unknown";
	year = 1990;
}

void Worker::setFio(string str)
{
	fio = str;
}

void Worker::setJob(string str)
{
	job = str;
}

void Worker::setYear(int y)
{
	year = y;
}

string Worker::getFio()
{
	return fio;
}

string Worker::getJob()
{
	return job;
}

int Worker::getYear()
{
	return year;
}



std::istream& operator>>(std::istream& in, Worker& w)
{
	std::cout << "fio: ";
	in.clear();

	string str;
	getline(in, str);
	w.setFio(str);

	std::cout << "job title: ";
	in.clear();
	getline(in, str);
	w.setJob(str);

	int y = -1;
	while (y <= 0 || y > 2022)
	{
		std::cout << "year: ";
		in.clear();
		takeInt(&y);
	}
	w.setYear(y);

	in.sync();
	return in;
}

std::ostream& operator<<(std::ostream& os, Worker& w)
{
	return os << w.getFio() << " " << w.getJob() << " works since: " << w.getYear();
}

void Worker::edit()
{
	

	int c;
	while (true)
	{
		printf("\n\tedit worker menu\n");
		printf("-1 back to element choice\n1 edit this one\n");
		cout << "now value is: ";
		cout << *this << endl;
		takeInt(&c);
		switch (c)
		{
		case -1:
			return;

		case 1:
			printf("enter new values\n");
			cin >> *this;
			break;

		default:
			printf("invalid input\n");

		}
	}
}
