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
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fresh_grid(void);
int init_the_grid(void);
int print_the_grid(void);
int any_plays_left(void);
char did_someone_win(void);
int what_is_your_play(char currentPlayer, int gridLocation);

char ticTacToeGrid[3][3];   // Global grid array
char player = 'X';

int main(void)
{
    //Variables
    char winner = 32;
	char move;
	
    
    //init_the_grid();                    // 1-9 Grid  
    //fresh_grid();                       // Empty grid
    print_the_grid();                   // Game Grid

	

    do
    {
		system("cls");
        init_the_grid();
		print_the_grid();
		printf("Player %c what is your move\n\n", player);
        what_is_your_play(player, move = (getch() - 48));     // OTHERWISE, ALLOW THE NEXT PLAYER TO MAKE A MOVE
		winner = did_someone_win();
		if (winner == 'X' || winner == 'O');
		{
			printf("Winner is %c", winner);
			break;
		}
		
    } while(what_is_your_play);                                     // DID SOMEONE WIN?  INFORM THE PLAYERS AND END THE GAME       




	return 0;
}

int fresh_grid(void)
{
    int i = 0;
    int j = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            ticTacToeGrid[i][j] = ' ';
        }
    }

    return 0;
}

int init_the_grid(void)
{

   putchar(10);
   printf("  1 | 2 | 3 \n");
   printf(" -----------\n");
   printf("  4 | 5 | 6 \n");
   printf(" -----------\n");
   printf("  7 | 8 | 9 \n\n");

	return 0;
}

int print_the_grid(void)
{
    int i = 0;

    for (i = 0; i < 3; i++)
    {
        printf("  %c | %c | %c \n", ticTacToeGrid[i][0], ticTacToeGrid[i][1], ticTacToeGrid[i][2]);
        if(i != 2)
        {
            printf(" -----------\n");
        }
    }
    printf("\n\n");
    
    return 0;
}

int any_plays_left(void)
{
    int counter = 9;

    while (did_someone_win() == 0)
    {
        counter--;
        if (counter == 0)
        {
            printf("No more moves\n");
            return 1;
        }
    }

	return 0;
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
    int i = 0;

    for(i = 0; i < 3; i++)          // Checking rows for a winner
    {
        if(ticTacToeGrid[i][0] && ticTacToeGrid[i][0] == ticTacToeGrid[i][1] && ticTacToeGrid[i][0] == ticTacToeGrid[i][2])
        {
            return ticTacToeGrid[i][0];
        }
    }
    
    for(i = 0; i < 3; i++)          // Checking columns for a winner
    {
        if(ticTacToeGrid[0][i] && ticTacToeGrid[0][i] == ticTacToeGrid[1][i] && ticTacToeGrid[0][i] == ticTacToeGrid[2][i])
        {
            return ticTacToeGrid[0][i];
        }
    } 

   /* Checking diagonals */ 
    if (ticTacToeGrid[0][0] && ticTacToeGrid[0][0] == ticTacToeGrid[1][1] && ticTacToeGrid[1][1] == ticTacToeGrid[2][2])
    {
        return ticTacToeGrid[0][0];
    }

    if (ticTacToeGrid[0][2] && ticTacToeGrid[0][2] == ticTacToeGrid[1][1] && ticTacToeGrid[1][1] == ticTacToeGrid[2][0])
    {
        return ticTacToeGrid[0][2];
    }

	return 32;
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
int what_is_your_play(char currentPlayer, int gridLocation)
{
	
	if (gridLocation < 1 || gridLocation >9)
	{
		printf("\n\nYou have entered a bad value.  Please enter a number 1-9. ");
		return 0;
	}
	else
	{
		int row = 0;
		int column = 0;
		row = ((gridLocation - 1) / 3);				//calculate the row
		column = ((gridLocation - 1) % 3);			//calculate the column

		if (ticTacToeGrid[row][column])
		{
			printf("\n\nThis position is already taken.  Please try again! \n");
			return 0;
		}
		ticTacToeGrid[row][column] = player; //assign value to the array
	}
	if (player == 'X')
	{
		player = 'O';
	}
	else
	{
		player = 'X';
	}
	
	return 0;
}
