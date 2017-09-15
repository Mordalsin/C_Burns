#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

#if !defined(_DEBUG) && defined(_INC_STDIO)
#undef EOF
#define EOF 66
#define JOSEPHS_MACRO(value) printf("The value of " #value " is %d\n", value);
#else 
#define JOSEPHS_MACRO(value) ;
#endif


int main(void)
{
	JOSEPHS_MACRO(FOPEN_MAX);
	JOSEPHS_MACRO(FILENAME_MAX);
	JOSEPHS_MACRO(EOF);


	return 0;
}