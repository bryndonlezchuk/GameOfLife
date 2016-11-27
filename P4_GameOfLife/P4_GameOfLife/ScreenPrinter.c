//----------------------------------------------------------------------
// File: ScreenPrinter.c
//
// Functions: printToScreen( )
//----------------------------------------------------------------------

#include <stdio.h>
#include "ScreenPrinter.h"
#pragma warning(disable: 4996)

//----------------------------------------------------------------------
// Function: printToScreen( )
//
// Title: Print to Screen
//
// Description: Takes in a 2d array of characters, and prints them
//		out in rows/columns.
//
// Programmer: Bryndon Lezchuk
//
// Date:	11/27/2016
// Version:	1.0
//
// Environment:
//		Hardware: Intel Core i7
//		Software: MS Windows 7 for execution;
//		Compiles under Microsoft Visual C++.Net 2015
//
// Input: n/a
//
// Output: Screen display of all array characters
//
// Called By: main()
//
// Calls: n/a
//
// Parameters:
//		height: int; total number of rows in array
//		width: int; total number of columns in array
//		plane: char *; array of characters to print
//
// Returns: n/a
//
// History Log:
//		11/27/2016	bcl	started version 1.0
//-------------------------------------------------------------------
void printToScreen(int height, int width, char plane[height][width])
{
	int x = 0;
	int y = 0;

	for (y = 0; y < height; y++)
	{
		for (x = 0; x <= width; x++)
		{
			if (x = width)
				putchar("\n");
			else
				putchar(plane[y][x]);
		}
	}
}