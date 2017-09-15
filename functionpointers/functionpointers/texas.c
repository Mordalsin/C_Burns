/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 8 /////////////////////////////////////////////
///////////////////////////////////////////////// FUNCTION POINTERS /////////////////////////////////////////////////
/////////////////////////////////////////// "Every integer is bigger in Texas" //////////////////////////////////////
///////////////////////////////////////////////// Instructor Solution ///////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Define each of the following function prototypes IAW their associated comment blocks:
//     int low_to_high_compare(int x, int y)
//     int high_to_low_compare(int x, int y)
//     int absolute_low_to_high_compare(int x, int y)
//     int absolute_high_to_low_compare(int x, int y)
// Write eight (8) tests for bubble_sort() (see: the comment block below), two tests for each of the function
//     prototypes listed above. 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <math.h>

#ifndef TRUE
#define TRUE ((int)1)
#endif

#ifndef FALSE
#define FALSE ((int)0)
#endif

/*
 * FUNCTION:   low_to_high_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:	   If x is greater than or equal to y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If x is greater than or equal y, y needs to be "bubbled up" to the top
 *             Large numbers are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 1
 *             x = 8, y = 68, return 0
 *             x = -24, y = 318, return 0
 *             x = -318, y = -688, return 1
 */
int low_to_high_compare(int x, int y);				// Choice 1

/*
 * FUNCTION:   int high_to_low_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:	   If x is less than or equal to y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If x is less than or equal y, y needs to be "bubbled up" to the top
 *             Large numbers are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 0
 *             x = 8, y = 68, return 1
 *             x = -24, y = 318, return 1
 *             x = -318, y = -688, return 0
 */
int high_to_low_compare(int x, int y);				// Choice 2

/*
 * FUNCTION:   int absolute_low_to_high_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 *  RETURNS:   If the absolute value of x is greater than or equal to the absolute value of y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If the absolute value of x is greater than or equal the absolute value of y,
 *                 y needs to be "bubbled up" to the top
 *             This function will not attempt to modify the values of x and y
 *             Smaller numbers, regardless of 'sign', are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 1
 *             x = 8, y = 68, return 0
 *             x = -24, y = 318, return 0
 *             x = -318, y = -688, return 0
 */
int absolute_low_to_high_compare(int x, int y);		// Choice 3

/*
 * FUNCTION:   absolute_high_to_low_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:    If the absolute value of x is less than or equal to the absolute value of y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If the absolute value of x is less than or equal the absolute value of y,
 *                 y needs to be "bubbled up" to the top
 *             This function will not attempt to modify the values of x and y
 *             Large numbers, regardless of 'sign', are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 0
 *             x = 8, y = 68, return 1
 *             x = -24, y = 318, return 1
 *             x = -318, y = -688, return 1
 */
int absolute_high_to_low_compare(int x, int y);		// Choice 4


/*
 * FUNCTION:   bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
 *
 * ARGUMENTS:  arrayOfInts - a pointer to an array of integers
 *             numOfElements - the dimension of the integer array found at the int pointer arrayOfInts
 *             compare_function - a function pointer; This function should take two ints as parameters
 *                 and return an int.  The expectation is that compare_function performs a comparison
 *                 of the two ints and returns a boolean value.  This boolean value should represent
 *                 whether or not the two ints should be swapped.  If the return value of compare_function
 *                 is 1, then the two ints should be swapped in place.
 *
 * RETURNS:    The total number of int swaps that were made
 *             0 if no swaps were made
 *             -1 if any pointer is NULL
 *             -2 if numOfElements is unrealistic
 *             -3 on any other error             
 *
 * NOTES:      This function is already defined below.  Do not modify this function.
 *             This function will sort, in place, the first "numOfElements" elements that are found
 *                 in the integer array found at pointer "arrayOfInts".  To accomplish this, bubble_sort()
 *                 will utilize the comparison function found at "compare_function" to accomplish this.
 *                 The expectation is that compare_function will compare two ints, n1 and n2.  In this, it
 *                 is expected that n1 comes before n2.  If n1 needs to swap with n2, compare_function will
 *                 return 1.  If not, compare_function will return 0.  Any other return value from
 *                 compare_function will be considered an error value (see: RETURNS).
 */
int bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int));

int main(void)
{

	// Iterating Variables
	int i = 0;
	int j = 0;
	int randInt;

	srand(time(NULL));
	
	

	int randomArray[10];

	for (i = 0; i < 10; i++)
	{
		randInt = rand() % 100 + 1;
		randomArray[i] = randInt;
	}


	// Temp variables
	int tempReturnValue = 0;
	int testNumber = 0;
	int testPassed = 0;
	int fullArraySuccess = 0;

	// Declare function pointer
	int(*bubble_ptr)(int m, int n);

	/*Test input for low to high*/
	int testInput0[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int testInput1[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	/*Test input for high to low*/
	int testInput2[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	int testInput3[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	/*Test input for ABS low to high*/
	int testInput4[] = { -1, -2, -3, -4, -5, -6, -7, -8 };
	int testInput5[] = { -8, -7, -6, -5, -4, -3, -2, -1 };

	/*Test input for ABS high to low*/
	int testInput6[] = { -8, -7, -6, -5, -4, -3, -2, -1 };
	int testInput7[] = { -1, -2, -3, -4, -5, -6, -7, -8 };


	// Array of expected return values
	int exptdRslts[] = { 0, 28, 0, 28, 0, 28, 0, 28 };


	/*Expected Results for low to high*/
	int exptdRslt0[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int exptdRslt1[] = { 1, 2, 3, 4, 5, 6, 7, 8 };

	/*Expected Results for high to low*/
	int exptdRslt2[] = { 8, 7, 6, 5, 4, 3, 2, 1 };
	int exptdRslt3[] = { 8, 7, 6, 5, 4, 3, 2, 1 };

	/*Expected Results for ABS low to high*/
	int exptdRslt4[] = { -1, -2, -3, -4, -5, -6, -7, -8 };
	int exptdRslt5[] = { -1, -2, -3, -4, -5, -6, -7, -8 };

	/*Expexted Results for ABS high to low*/
	int exptdRslt6[] = { -8, -7, -6, -5, -4, -3, -2, -1 };
	int exptdRslt7[] = { -8, -7, -6, -5, -4, -3, -2, -1 };

	//Test name array
	char testName0[] = { "Low to High Tests" };
	char testName1[] = { "High to Low Tests" };
	char testName2[] = { "ABS Low to high Tests" };
	char testName3[] = { "ABS High to Low Tests" };



	//Array of test arrays
	char * nameArrays[] = { testName0, testName0, testName1, testName1, testName2, testName2, testName3, testName3 };


	// Array of test input arrays
	int * arrayOfTestInput[] = { testInput0, testInput1, testInput2, testInput3, \
		testInput4, testInput5, testInput6, testInput7 };

	// Array of expted result arrays
	int * arrayOfExptdRslt[] = { exptdRslt0, exptdRslt1, exptdRslt2, exptdRslt3, \
		exptdRslt4, exptdRslt5, exptdRslt6, exptdRslt7 };

	int(*arrOfFunPts[]) = { &low_to_high_compare , &low_to_high_compare, \
		&high_to_low_compare, &high_to_low_compare, \
		&absolute_low_to_high_compare, &absolute_low_to_high_compare, \
		&absolute_high_to_low_compare, &absolute_high_to_low_compare };

	printf("\n\n*********| Before bubble sort |**********\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", randomArray[i]);
	}
	printf("\n************************************\n\n");

	bubble_sort(randomArray, 10, &low_to_high_compare);


	printf("\n\n*********| After bubble sort |**********\n");
	for (i = 0; i < 10; i++)
	{
		printf("%d, ", randomArray[i]);
	}
	printf("\n************************************\n\n");


	for (i = 0; i < 8; i++)
	{

		printf("\n\n*******************\n");
		printf("%s\n", *(nameArrays + i));
		printf("*******************\n");


		if (i < 2)										// 2 tests for low to high
		{
			bubble_ptr = &low_to_high_compare;
		}
		else if (i > 1 && i < 4)						// 2 tests for high to low
		{
			bubble_ptr = &high_to_low_compare;
		}
		else if (i > 3 && i < 6)						// 2 tests for ABS low to high
		{
			bubble_ptr = &absolute_low_to_high_compare;
		}
		else											// 2 tests for ABS high to low
		{
			bubble_ptr = &absolute_high_to_low_compare;
		}

		tempReturnValue = bubble_sort(*(arrayOfTestInput + i), 8, (*(arrOfFunPts + i)));	// Store results from bubble sort

		testNumber++;
		printf("Return Value:\t\t");

		if (tempReturnValue == *(exptdRslts + i))		// Compare results
		{
			printf("Pass\n");
			testPassed++;
		}
		else
		{
			printf("Error\n");
		}
		printf("Return Array Test:\t");

		
		fullArraySuccess = 0;
		for (j = 0; j < 8; j++)
		{
			if (*(*(arrayOfTestInput + i) + j) == *(*(arrayOfExptdRslt + i) + j))
			{
				fullArraySuccess++;
			}
			else
			{
				printf("Error\n");
				break;
			}
		}
		testNumber++;
		if (fullArraySuccess == 8)
		{
			printf("Pass");
			testPassed++;
		}
	}
	puts("\n\n\n*************************");
	printf("%d tests were run.\n%d tests passed.\n", testNumber, testPassed);
	puts("*************************");

	return 0;
}

/*
 * FUNCTION:   low_to_high_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:	   If x is greater than or equal to y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If x is greater than or equal y, y needs to be "bubbled up" to the top
 *             Large numbers are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 1
 *             x = 8, y = 68, return 0
 *             x = -24, y = 318, return 0
 *             x = -318, y = -688, return 1
 */
int low_to_high_compare(int x, int y)
{
	if (x > y)
	{
		return 1;
	}
	return 0;
}

/*
 * FUNCTION:   int high_to_low_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:	   If x is less than or equal to y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If x is less than or equal y, y needs to be "bubbled up" to the top
 *             Large numbers are ordered first
 * 
 * EXAMPLES:   x = 9, y = 0, return 0
 *             x = 8, y = 68, return 1
 *             x = -24, y = 318, return 1
 *             x = -318, y = -688, return 0
 */
int high_to_low_compare(int x, int y)
{
	if (x < y)
	{
		return 1;
	}
	return 0;
}

/*
 * FUNCTION:   int absolute_low_to_high_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 *  RETURNS:   If the absolute value of x is greater than or equal to the absolute value of y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If the absolute value of x is greater than or equal the absolute value of y,
 *                 y needs to be "bubbled up" to the top
 *             This function will not attempt to modify the values of x and y
 *             Smaller numbers, regardless of 'sign', are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 1
 *             x = 8, y = 68, return 0
 *             x = -24, y = 318, return 0
 *             x = -318, y = -688, return 0
 */
int absolute_low_to_high_compare(int x, int y)
{
	if (abs(x) > abs(y))
	{
		return 1;
	}
	return 0;
}

/*
 * FUNCTION:   absolute_high_to_low_compare(int x, int y)
 *
 * ARGUMENTS:  Two sequential integers to compare
 *             For the sake of ordering, x should come before y
 *
 * RETURNS:    If the absolute value of x is less than or equal to the absolute value of y, return 1
 *             On error, return -1
 *             Return 0 for all other conditions
 *
 * NOTES:      This function compares the values of x and y
 *             If the absolute value of x is less than or equal the absolute value of y,
 *                 y needs to be "bubbled up" to the top
 *             This function will not attempt to modify the values of x and y
 *             Large numbers, regardless of 'sign', are ordered first
 *
 * EXAMPLES:   x = 9, y = 0, return 0
 *             x = 8, y = 68, return 1
 *             x = -24, y = 318, return 1
 *             x = -318, y = -688, return 1
 */
int absolute_high_to_low_compare(int x, int y)
{
	if (abs(x) < abs(y))
	{
		return 1;
	}
	return 0;
}

/*
 * FUNCTION:   bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
 *
 * ARGUMENTS:  arrayOfInts - a pointer to an array of integers
 *             numOfElements - the dimension of the integer array found at the int pointer arrayOfInts
 *              compare_function - a function pointer; This function should take two ints as parameters
 *                 and return an int.  The expectation is that compare_function performs a comparison
 *                 of the two ints and returns a boolean value.  This boolean value should represent
 *                 whether or not the two ints should be swapped.  If the return value of compare_function
 *                 is 1, then the two ints should be swapped in place.
 *
 * RETURNS:    The total number of int swaps that were made
 *             0 if no swaps were made
 *             -1 if any pointer is NULL
 *             -2 if numOfElements is unrealistic
 *             -3 on any other error
 *
 * NOTES:      This function is already defined below.  Do not modify this function.
 *             This function will sort, in place, the first "numOfElements" elements that are found
 *                 in the integer array found at pointer "arrayOfInts".  To accomplish this, bubble_sort()
 *                 will utilize the comparison function found at "compare_function" to accomplish this.
 *                 The expectation is that compare_function will compare two ints, n1 and n2.  In this, it
 *                 is expected that n1 comes before n2.  If n1 needs to swap with n2, compare_function will
 *                 return 1.  If not, compare_function will return 0.  Any other return value from
 *                 compare_function will be considered an error value (see: RETURNS).
 */
int bubble_sort(int * arrayOfInts, int numOfElements, int(*compare_function)(int, int))
{
	int returnValue = -3;	// Default return value in case something dies
	int i = 0;				// Iterating variable
	int j = 0;				// Iterating variable
	int swapCount = 0;		// Number of element swaps that have been made

	if (!arrayOfInts || !compare_function)	// If either of the pointers are NULL...
	{
		returnValue = -1;	// ...return -1
	}
	else if (numOfElements < 2) // If the number of elements is unrealistic...
	{
		returnValue = -2; // ...return -2
	}
	else
	{
		for (i = 0; i < numOfElements; i++) // Iterate through all of the elements...
		{
			for (j = 0; j < (numOfElements - 1); j++) // ...comparing each element to all the other elements
			{
				if ((compare_function(*(arrayOfInts + j), *(arrayOfInts + j + 1))) > 0) // If the compare function suggests a swap...
				{
					/* ...swap the values stored in each element */
					*(arrayOfInts + j)		= *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					*(arrayOfInts + j + 1)	= *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					*(arrayOfInts + j)		= *(arrayOfInts + j) ^ *(arrayOfInts + j + 1);
					swapCount++; // A swap took place so increment the number of swaps counted
				}
			}
		}
		returnValue = swapCount; // Return the total number of swaps that took place
	}
	
	return returnValue;
}
