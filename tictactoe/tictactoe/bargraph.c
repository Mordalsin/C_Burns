#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define ROWS 5
#define COLUMNS 16
#define CHARACTER_ONE ((char)240)
#define CHARACTER_TWO ((char)220)
#define CHARACTER_THREE ((char)279)
#define CHARACTER_FOUR ((char)277)

int main(void)
{
	//Variables
	int row = 0;
	int col = 0;

	char barGraphArray[ROWS][COLUMNS] = { 0 };

	/*Populate the first bar*/
	for (row = 2; row < ROWS; row++)
	{
		for (col = 0; col < 3; col++)
		{
			*(*(barGraphArray + row) + col) = CHARACTER_ONE;
		}
	}

	/*Populate the second bar*/
	for (row = 0; row < ROWS; row++)
	{
		for (col = 4; col < 7; col++)
		{
			*(*(barGraphArray + row) + col) = CHARACTER_TWO;
		}
	}

	/*Populate the third bar*/
	for (row = 1; row < ROWS; row++)
	{
		for (col = 8; col < 11; col++)
		{
			*(*(barGraphArray + row) + col) = CHARACTER_THREE;
		}
	}

	/*Populate the fourth bar*/
	for (row = 3; row < ROWS; row++)
	{
		for (col = 12; col < COLUMNS - 1; col++)
		{
			*(*(barGraphArray + row) + col) = CHARACTER_FOUR;
		}
	}

	/*Print out the whole bar graph*/
	for (row = 0; row < ROWS; row++)
	{
		for (col = 0; col < COLUMNS; col++)
		{
			putchar(barGraphArray[row][col]);
		}
		putchar(10);
	}


	//for (int i = 0; i < 255; i++)
	//{
	//	printf("%c\n", i);
	//}
	return 0;
}