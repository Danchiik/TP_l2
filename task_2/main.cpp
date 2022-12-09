/*
2. �������� � ��������� ������
� �������������� �������� � ��������� ������� �������� ���������,
������� ��������� ����� �� ����� � ������� �� ����� ������ �����������,
�� ���������� �������.
*/

#include <iostream>

#include <iostream>
#include <fstream>

using namespace std;

bool isEndSymbol(string ch)
{
	return (ch == "." || ch == "!" || ch == "?" || ch == "\"");
}

bool isEndSymbol_and_spaces(string ch)
{
	return (ch == "." || ch == "!" || ch == "?" || ch == "\"" || ch == " " || ch == "\t" || ch == "\n");
}

void my_read_file()
{
	ifstream fin;
	string filename = "text.txt";

	fin.open(filename);
	if (!fin.is_open())
	{
		throw "EXEPTION: no file such as " + filename + " was found";
	}

	string centence;
	string sym;
	char ch;
	bool z_met = false;
	while (!fin.eof())
	{
		fin.get(ch);
		sym = ch;
		if (isEndSymbol(sym))
		{
			if (!z_met)
				cout << centence << endl;
			centence = "";
			z_met = false;
			while (!fin.eof() && isEndSymbol_and_spaces(sym))
			{
				fin.get(ch);
				sym = ch;
				if (!isEndSymbol_and_spaces(sym))
					centence += sym;
			}
		}
		else
		{
			if (sym == ",")
				z_met = true;
			centence += sym;
		}
		
	}

	if (!z_met)
		cout << centence << endl;
	fin.close();
}


int main()
{
	try {
		my_read_file();
	}
	catch (string m)
	{
		cout << m << endl;
	}

	return 0;
}