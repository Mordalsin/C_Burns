#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define COMBINE_STRING_LITERAL(x, y) x##y
#define PREPARE_COMBINE_STRING(x, y) COMBINE_STRING_LITERAL(x, y)
#define STRING_IN_QUOTES(a) #a
#define PREPARE_STRING_IN_QUOTES(a) STRING_IN_QUOTES(a)
#define BUFF_SIZE 64

/*********************************************************************
/   AUTHOR:    Joseph Burns
*********************************************************************/
int main(void)
{


	char myArray[BUFF_SIZE] = PREPARE_STRING_IN_QUOTES(PREPARE_COMBINE_STRING(Joseph, Burns));
	printf("%s", myArray);


	return 0;
}