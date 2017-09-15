/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////// MQT (I.5.A) PERFORMANCE LAB 1 ////////////////////////////////////////////
///////////////////////////////////////////////// MEMORY OPERATORS //////////////////////////////////////////////////
////////////////////////////////////////////// "Reference Not Found" ////////////////////////////////////////////////
/////////////////////////////////////////////// Instructor Solution /////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Declare userInput, tempValue, and input_ptr as the same data type (and input_ptr should be a pointer variable)
// Read user input into variable userInput
// Ensure tempValue contains the same value as userInput utilizing one or more memory operators
//     tempValue = userInput;  // NOT PERMITTED... use a memory operator
// Print the value *and* the pointer for each of the three variables in a human-readable format
// Locate those addresses in the "memory window"
// Summon your instructor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define HUMAN_READABLE_CHAR(printChar) printf(#printChar " has a value of %c(%d) at pointer %p.\n", printChar, (int)printChar, &printChar)
#define HUMAN_READABLE_POINTER(printPointer) printf(#printPointer " has a value of %p which is stored at pointer %p.\n", printPointer, &printPointer)

int main(void)
{
	/* Declare userInput, tempValue, and input_ptr as the same data type (and input_ptr should be a pointer variable) */
	int userInput = 0;
	int tempValue = 0;
	int * input_ptr = 0;
	
	/* Read user input into variable userInput */
	printf("Type a freaking number already:\n");
	scanf("%d", &userInput);

	/* Ensure tempValue contains the same value as userInput utilizing one or more memory operators */
	input_ptr = &userInput;
	tempValue = *input_ptr;

	/* Print the value *and* the pointer for each of the three variables in a human-readable format */
	//printf("userInput - Value: %d	Pointer: %d\ntempValue - Value: %d	Pointer: %d\ninput_ptr - Value: %d	Pointer: %d", userInput, &userInput, tempValue, &tempValue, *input_ptr, input_ptr);

	HUMAN_READABLE_CHAR(userInput);
	//UMAN_READABLE_POINTER(userInput);
	HUMAN_READABLE_CHAR(tempValue);
	HUMAN_READABLE_POINTER(input_ptr);

	return 0;
}
