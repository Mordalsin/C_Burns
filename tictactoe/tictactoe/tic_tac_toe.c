/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////// PERFORMANCE LAB (I.5.A) 6 /////////////////////////////////////////////
////////////////////////////////////////////// MULTI-DIMENSIONAL ARRAYS /////////////////////////////////////////////
//////////////////////////////////////////////////// "Tic Tac Toe" //////////////////////////////////////////////////
////////////////////////////////////////////////////// Stub Code ////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Replicate a tic tac toe grid using a two-dimensional char array of global scope (for ease of use)
// Define the following prototype functions in main(void) according to their specifications:
//     int printTheGrid(void);
//     int any_plays_left(void);
//     char did_someone_win(void);
//     int what_is_your_play(char currentPlayer, int gridLocation);
// Loop through those functions, in the order listed above and below, taking input until:
//     Someone wins *or*
//     There are no more selections (stalemate)
// Check for bad input (e.g., Selection 99) and reported errors (e.g., what_is_your_play() should return -1 on
//     an invalid selection)
// Direct reference to array elements (e.g., myArray[0][1]) is authorized.  In other words, pointer arithmetic
//     is not mandatory.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>

/*
 * FUNCTION:   int print_the_grid(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, 1
 *             On failure, 0
 *
 * NOTES:      This function should first print out a tic tac toe legend:
 *              1 | 2 | 3
 *             -----------
 *              4 | 5 | 6
 *             -----------
 *              7 | 8 | 9
 *
 *             Then, this function should print out the current state of the 2D char array in a similar format:
 *                |   | X
 *             -----------
 *              X | O |
 *             -----------
 *                |   |
 */
int print_the_grid(void);

/*
 * FUNCTION:   int any_plays_left(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the number of available choices
 *             On failure, 0
 *
 * NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
 */
int any_plays_left(void);

/*
 * FUNCTION:   char did_someone_win(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
 *             On failure, 0
 *
 * NOTES:      There are 8 possible win conditions:
 *                 Top row, middle row, bottom row
 *                 Left column, middle column, right column
 *                 Backslash, "Frontslash" (TM pending)
 */
char did_someone_win(void);

/*
 * FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
 *
 * ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
 *             int gridLocation should indicate the position on the grid to place "currentPlayer" as
 *                 defined by whomever defined print_the_grid().
 *
 * RETURNS:	   On a successful choice, 1
 *             If the user chooses a location that has already been taken, 0
 *             On failure, -1
 *
 * NOTES:      Verify that gridLocation has not already been chosed before accepting the play
 *             If the play is valid, record the selection within the 2D tic tac toe array
 */
int what_is_your_play(int gridLocation);

/* TIC TAC TOE char array */
char ticTacToeGrid[3][3] = { ' ' };
int gridLocation;  //initialize gridLocation
char currentPlayer = 'X';

int main(void)
{
	//initialize the grid
	int i = 0;  //incrementers ot initialize the grid
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			ticTacToeGrid[i][j] = ' ';
		}
	}

	//Set first player to X

	//Start the game
	while (any_plays_left)  //While any moves are left run this loop
	{
		/* PRINT THE LEGEND AND CURRENT STATUS OF THE GAME */
		print_the_grid();
		/* DETERMINE IF THERE ARE NO MORE MOVES LEFT */
		any_plays_left();
		/* DID SOMEONE WIN?  INFORM THE PLAYERS AND END THE GAME */
		if (did_someone_win() == 1)
		{
			break;
		}

		/* OTHERWISE, ALLOW THE NEXT PLAYER TO MAKE A MOVE */
		//what_is_your_play(currentPlayer, 0);
		//prompts for moves

		do
		{
			printf("The current player is %c.\n", currentPlayer);
			printf("%c where would you like to place your marker? \n", currentPlayer);
			scanf_s("%i", &gridLocation);
		} while (what_is_your_play(gridLocation));
	}


	// NOTE:  Don't forget error checking and input validation along the way.

	return 0;
}
/*
 * FUNCTION:   int printTheGrid(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, 1
 *             On failure, 0
 *
 * NOTES:      This function should first print out a tic tac toe legend:
 *              1 | 2 | 3
 *             -----------
 *              4 | 5 | 6
 *             -----------
 *              7 | 8 | 9
 *
 *             Then, this function should print out the current state of the 2D char array in a similar format:
 *                |   | X
 *             -----------
 *              X | O |
 *             -----------
 *                |   |
 */
int print_the_grid(void)
{
	system("cls");

	putchar(10);
	printf(" 1 | 2 | 3 \n");
	printf("-----------\n");
	printf(" 4 | 5 | 6 \n");
	printf("-----------\n");
	printf(" 7 | 8 | 9 \n");

	putchar(10);
	putchar(10);
	printf(" %c | %c | %c \n", ticTacToeGrid[0][0], ticTacToeGrid[0][1], ticTacToeGrid[0][2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n", ticTacToeGrid[1][0], ticTacToeGrid[1][1], ticTacToeGrid[1][2]);
	printf("-----------\n");
	printf(" %c | %c | %c \n\n", ticTacToeGrid[2][0], ticTacToeGrid[2][1], ticTacToeGrid[2][2]);

	return 0;
}

/*
 * FUNCTION:   int any_plays_left(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the number of available choices
 *             On failure, 0
 *
 * NOTES:      This function should count and return the number of remaining 'moves' from the 2D array
 */
int any_plays_left(void)
{
	int i = 0;		// iterators
	int j = 0;
	int count = 0;	// space count

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (ticTacToeGrid[i][j] == ' ')
			{
				count++;
			}
		}
	}
	printf("testing! there are %d moves left\n", count); //checking value during testing
	return count;
}

/*
 * FUNCTION:   char did_someone_win(void)
 *
 * ARGUMENTS:  NONE
 *
 * RETURNS:	   On success, the character of the winner (should be either 'X' or 'O') or 0 for "no winner"
 *             On failure, 0
 *
 * NOTES:      There are 8 possible win conditions:
 *                 Top row, middle row, bottom row
 *                 Left column, middle column, right column
 *                 Backslash, "Frontslash" (TM pending)
 */
char did_someone_win(void)
{
	// interators
	if ((ticTacToeGrid[0][0] == 'X' && ticTacToeGrid[0][1] == 'X' && ticTacToeGrid[0][2] == 'X') || \
		(ticTacToeGrid[0][0] == 'X' && ticTacToeGrid[1][1] == 'X' && ticTacToeGrid[2][2] == 'X') || \
		(ticTacToeGrid[0][0] == 'X' && ticTacToeGrid[1][0] == 'X' && ticTacToeGrid[2][0] == 'X') || \
		(ticTacToeGrid[0][1] == 'X' && ticTacToeGrid[1][1] == 'X' && ticTacToeGrid[2][1] == 'X') || \
		(ticTacToeGrid[0][2] == 'X' && ticTacToeGrid[1][2] == 'X' && ticTacToeGrid[2][2] == 'X') || \
		(ticTacToeGrid[1][0] == 'X' && ticTacToeGrid[1][1] == 'X' && ticTacToeGrid[1][2] == 'X') || \
		(ticTacToeGrid[2][0] == 'X' && ticTacToeGrid[1][1] == 'X' && ticTacToeGrid[0][2] == 'X') || \
		(ticTacToeGrid[2][0] == 'X' && ticTacToeGrid[2][1] == 'X' && ticTacToeGrid[2][2] == 'X') || \
		(ticTacToeGrid[2][0] == 'X' && ticTacToeGrid[1][1] == 'X' && ticTacToeGrid[0][2] == 'X'))
	{
		printf("X Wins!");
		return 1;
	}

	if ((ticTacToeGrid[0][0] == 'O' && ticTacToeGrid[0][1] == 'O' && ticTacToeGrid[0][2] == 'O') || \
		(ticTacToeGrid[0][0] == 'O' && ticTacToeGrid[1][1] == 'O' && ticTacToeGrid[2][2] == 'O') || \
		(ticTacToeGrid[0][0] == 'O' && ticTacToeGrid[1][0] == 'O' && ticTacToeGrid[2][0] == 'O') || \
		(ticTacToeGrid[0][1] == 'O' && ticTacToeGrid[1][1] == 'O' && ticTacToeGrid[2][1] == 'O') || \
		(ticTacToeGrid[0][2] == 'O' && ticTacToeGrid[1][2] == 'O' && ticTacToeGrid[2][2] == 'O') || \
		(ticTacToeGrid[1][0] == 'O' && ticTacToeGrid[1][1] == 'O' && ticTacToeGrid[1][2] == 'O') || \
		(ticTacToeGrid[2][0] == 'O' && ticTacToeGrid[1][1] == 'O' && ticTacToeGrid[0][2] == 'O') || \
		(ticTacToeGrid[2][0] == 'O' && ticTacToeGrid[2][1] == 'O' && ticTacToeGrid[2][2] == 'O') || \
		(ticTacToeGrid[2][0] == 'O' && ticTacToeGrid[1][1] == 'O' && ticTacToeGrid[0][2] == 'O'))
	{
		printf("O Wins!");
		return 1;
	}

	return 0;
}

/*
 * FUNCTION:   int what_is_your_play(char currentPlayer, int gridLocation)
 *
 * ARGUMENTS:  char currentPlayer should either be 'X' or 'O' to represent the char to store
 *             int gridLocation should indicate the position on the grid to place "currentPlayer" as
 *                 defined by whomever defined print_the_grid().
 *
 * RETURNS:	   On a successful choice, 1
 *             If the user chooses a location that has already been taken, 0
 *             On failure, -1
 *
 * NOTES:      Verify that gridLocation has not already been chosed before accepting the play
 *             If the play is valid, record the selection within the 2D tic tac toe array
 */
int what_is_your_play(char gridLocation)
{
	if (gridLocation < 1 || gridLocation >9)
	{
		printf("\n\nYou have entered a bad value.  Please enter a number 1-9. ");
		scanf_s("%i", &gridLocation);
		printf("%c", currentPlayer);
		return 0;
	}
	else
	{
		int row = 0;
		int column = 0;
		row = ((gridLocation - 1) / 3);				//calculate the row
		column = ((gridLocation - 1) % 3);			//calculate the column

		if (ticTacToeGrid[row][column] != ' ')
		{
			printf("\n\nThis position is already taken.  Please try again! \n");
			return 0;
		}
		ticTacToeGrid[row][column] = currentPlayer; //assign value to the array
	}
	if (currentPlayer == 'X')
	{
		currentPlayer = 'O';
	}
	else
	{
		currentPlayer = 'X';
	}



	return 1;
}
