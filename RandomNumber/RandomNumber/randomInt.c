#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


int random_int(int low, int high);

int main()
{
	int lowNumber = 0;
	int highNumber = 0;
	do
	{
		printf("To generate a random number, pick a high and a low for it to pick between: (e.g. 1-100)\n(To exit make the first number negative)\n");
		scanf("%d-%d", &lowNumber, &highNumber);
		if (lowNumber < 0)
		{
			break;
		}
		printf("You randomly chosen number between %d and %d was: %d\n", lowNumber, highNumber, random_int(lowNumber, highNumber));
	}
	while (1);

	return 0;
}

int random_int(int low, int high)
{
	int newNumber = 0;
	int range = 0;
	
	range = high - low + 1;

	if (low >= high)
	{
		return -1;
	}
	else
	{
		return rand() % (high - low + 1) + low;
	}

	return newNumber;
}