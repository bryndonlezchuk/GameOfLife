//----------------------------------------------------------------------------
// File: walkthrough.c
//
// Functions:
//    walkthrough
//----------------------------------------------------------------------------
#include "getNeighbors.h"
#define ALIVE2 '*'
#define DEAD2 '.'
//----------------------------------------------------------------------------
// Function: walkthrough
//
// Title: Game of Life
//
// Description:
// Scans the entire array of the game of life program, and determines whether
// or not a cell is dead or alive.
//
// Programmer: David C
//
// Date: 12/1/16
//
// Version: 1.0
//
// Environment:
//	Intel Xeon PC
//	Software: OS: Windows 10
//	Compiles under Microsoft Visual Studio 2015
//
// Input:
// None (void)
//
// Output:	
// Passes a value of dead or alive.
//
// Parameters: char const *current, char next[ROWS][COLUMNS]
//
// Returns: None
//
// History Log:
//   12/1/16 DC completed version 1.0
//-----------------------------------------------------------------------------
void walkthrough(char const *current, char next[ROWS][COLUMNS])
{
	int x = COLUMNS, y = ROWS;
	int i = 0, j = 0;
	//scans the entire array
	for (i = 0; i < y; i++)
		for (j = 0; j < x; j++)
		{
			//calls the "isalive" function to determine
			//the status of a particular cell
			if (getNeighbors(current, i, j))
				next[i][j] = ALIVE2;
			else
				next[i][j] = DEAD2;
		}
}