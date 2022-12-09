#define _CRT_SECURE_NO_WARNINGS

#include "helper.h"

int takeInt(int* _x)
{
	while (1)
	{
		if (scanf("%d", _x) != 1)
			printf("invalid input, try again\n");
		else
		{
			if (getchar());
			return 1;
		}
		if (getchar());
	}
}
