//----------------------------------------------------------------------------
// File: walkthrough.c
//
// Functions:
//    walkthrough
//----------------------------------------------------------------------------
#include "Project4_Anthony.h"
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
// None
//
// Output:	
// Passes a value of dead or alive.
//
// Parameters: char current[ROWS][COLUMNS], char next[ROWS][COLUMNS]
//
// Returns: None
//
// History Log:
//   12/1/16 DC completed version 1.0
//-----------------------------------------------------------------------------
void walkthrough(char current[ROWS][COLUMNS], char next[ROWS][COLUMNS])
{
	int x = COLUMNS, y = ROWS;
	int i = 0, j = 0;
	//scans the entire array
	for (i = 0; i < y; i++)
		for (j = 0; j < x; j++)
		{
			//calls the "isalive" function to determine
			//the status of a particular cell
			if (isAlive(current, x, y))
				next[y][x] = ALIVE2;
			else
				next[y][x] = DEAD2;
		}
}