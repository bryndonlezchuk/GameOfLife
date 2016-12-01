//-----------------------------------------------------------------------------
// File: getNeighbors.c
//
// Functions: isAlive()
//			  getNeighbors()
//-----------------------------------------------------------------------------

#include "getNeighbors.h"
#include <stdlib.h>

//-----------------------------------------------------------------------------
// Function:	isAlive()
//
// Title:		Determines whether or not a cell is alive
//
// Description: Takes in a 2D array and an x/y cell's position and 
//				determines if the cell is alive or dead
//
// Programmer:	Anthony Waddell
//
// Date:		11/21/2016
// Version:		1.0
//
// Environment:
//				Hardware: Toshiba Satellite
//				Software: MS Windows 10 
//				Compiles under Microsoft Visual Studios 2015
//
// Input:		An array of cells (current generation) and the x/y location 
//				of a single cell
//
// Output:		n/a
//
// Called By:	main()
//
// Calls:		n/a
//
// Parameters:
//				array: char; an array of the current generation of cells
//				xcell: int; which row the specified cell is in
//				ycell: int; which column the specified cell is in
//
// Returns:		If cell is alive, returns 1. If not, returns 0.
//
// History Log:
//				11-21-16 Wrote Function
//-----------------------------------------------------------------------------
char isAlive(char array[ROWS][COLUMNS], int xcell, int ycell)
{
	char test = '!';

	if (array[xcell][ycell] == ALIVE)
	{
		test = ALIVE;
	}
	else if (ycell < 0)
	{
		test = DEAD;
	}
	else if (xcell < 0)
	{
		test = DEAD;
	}
	else if (ycell > COLUMNS)
	{
		test = DEAD;
	}
	else if (xcell > ROWS)
	{
		test = DEAD;
	}
	else {
		test = DEAD;
	}
	return test;
}

//-----------------------------------------------------------------------------
// Function:	getNeighbors()
//
// Title:		Counts the neighbors of a given cell
//
// Description: Given the an array of the current generation and the location
//				of a specified cell, looks at the 8 surrounding cells to 
//				get a count of the number of neighbors (living cells)
//
// Programmer:	Anthony Waddell
//
// Date:		11/21/2016
// Version:		1.0
//
// Environment:
//				Hardware: Toshiba Satellite
//				Software: MS Windows 10 
//				Compiles under Microsoft Visual Studios 2015
//
// Input:		An array of cells (current generation) and the x/y location 
//				of a single cell
//
// Output:		n/a
//
// Called By:	main()
//
// Calls:		isAlive()
//
// Parameters:
//				array: char; an array of the current generation of cells
//				row: int; which row the specified cell is in
//				column: int; which column the specified cell is in
//
// Returns:		If the the number of neighbors surrounding the cell is exactly 
//				2 or 3, the given cell will be returned as alive ('*'). If not, 
//				the cell will be returned as dead (' ').
//
// History Log:
//				11-21-16 Wrote Function
//-----------------------------------------------------------------------------
void getNeighbors(char array[ROWS][COLUMNS], int row, int column) {
	int neighbors = 0;

	if (isAlive(array, row - 1, column - 1) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row - 1, column) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row - 1, column + 1) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row, column - 1) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row, column + 1) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row + 1, column - 1) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row + 1, column) == ALIVE)
	{
		neighbors++;
	}
	if (isAlive(array, row + 1, column + 1) == ALIVE)
	{
		neighbors++;
	}

	//application of rules
	// I think these rules need to be applied outside of this fucnction
	// by the function that prints the next generation because this one eats up 
	// cells that have too few/many neighbors before it looks at the next cell. 


	if (neighbors == 3 || neighbors == 2)
	{
		array[row][column] = '*';
	}
	else if (neighbors < 2 || neighbors > 3)
	{
		array[row][column] = '.';
	}
}
