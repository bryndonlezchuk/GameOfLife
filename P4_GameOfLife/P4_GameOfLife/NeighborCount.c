#include "NeighborCount.h"

// Checks the value of any given cell. If the cell is dead, it will return false.
// If the cell is outside of the bounds, it will just return false.
// If the cell is alive, it will return true. 
int isAlive(char array[ROWS][COLUMNS], int xcell, int ycell)
{
	if (array[xcell][ycell] == DEAD)
	{
		return DEAD;
	}
	else if (ycell < 0)
	{
		return DEAD;
	}
	else if (xcell < 0)
	{
		return DEAD;
	}
	else if (ycell > COLUMNS)
	{
		return DEAD;
	}
	else if (xcell > ROWS)
	{
		return DEAD;
	}
	else {
		return ALIVE;
	}
}

// Takes the array of the current generation and the specified cell to count the neighbors. 
// returns the number of neighbors of the specified cell
// Will be used in a double for-loop that calculates the next generation to get the neighbor count of each cell
void getNeighbors(char array[ROWS][COLUMNS], int xcell, int ycell) {
	int neighbors = 0;
	neighbors =
		isAlive(array, xcell - 1, ycell - 1) +
		isAlive(array, xcell, ycell - 1) +
		isAlive(array, xcell + 1, ycell - 1) +
		isAlive(array, xcell - 1, ycell) +
		isAlive(array, xcell, ycell + 1) +
		isAlive(array, xcell - 1, ycell + 1) +
		isAlive(array, xcell, ycell + 1) +
		isAlive(array, xcell + 1, ycell + 1);
	if (neighbors > 3 || neighbors < 2)
	{
		array[xcell][ycell] = ' ';
	}
	if (neighbors == 2 || neighbors == 3)
	{
		array[xcell][ycell] = '*';
	}
}
