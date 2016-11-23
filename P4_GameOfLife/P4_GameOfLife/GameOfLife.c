//----------------------------------------------------------------------------
// File: GameOfLife.c
// Functions:
//		int main(int argc, char *argv[])
//----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "ScreenPrinter.c"

#define GRIDWIDTH 40
#define GRIDHEIGHT 20
#define GENERATIONS 2

int main(int argc, char *argv[])
{
	char array[GENERATIONS][GRIDHEIGHT][GRIDWIDTH];
	/*char lifeGrid[GRIDWIDTH][GRIDHEIGHT][GENERATIONS];*/
	FILE * inFileHandle = NULL;
	char filenameInput[FILENAME_MAX] = "";
	char prompt = 'n';
	int quit = 0;
	int returnValue = EXIT_SUCCESS;

	while (quit = 0)
	{
		switch (prompt)
		{
		case 'n':
		case 'N':
			//new file
			//readFile(inFileHandle
			break;
		case 'q':
		case 'Q':
			//quit
			quit = 1;
			break;
		default:
			//next generation
			break;
		}
	}
}



#define DEAD 0
#define ALIVE 1


// Checks the value of any given cell. If the cell is dead, it will return false.
// If the cell is outside of the bounds, it will just return false.
// If the cell is alive, it will return true. 
int isAlive(char array1[1][GRIDHEIGHT][GRIDWIDTH], int xcell, int ycell)
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
	else if (ycell > GRIDHEIGHT)
	{
		return DEAD;
	}
	else if (xcell > GRIDWIDTH)
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
//int getNeighbors(int array[ROWS][COLUMNS], int xcell, int ycell) {
//	int neighbors = 0;
//	neighbors =
//		isAlive(array, xcell - 1, ycell - 1) +
//		isAlive(array, xcell, ycell - 1) +
//		isAlive(array, xcell + 1, ycell - 1) +
//		isAlive(array, xcell - 1, ycell) +
//		isAlive(array, xcell, ycell + 1) +
//		isAlice(array, xcell - 1, ycell + 1) +
//		isAlive(array, xcell, ycell + 1) +
//		isAlive(array, xcell + 1, ycell + 1);
//	return neighbors;
//}



int getNeighborsNew(int array[GRIDHEIGHT][GRIDWIDTH])
{
	char nextGen[GRIDHEIGHT][GRIDWIDTH] = "";
	int neighbors = 0;

	for (int i = 1; i < GRIDHEIGHT - 1; i++)
	{
		for (int j = 0; j < GRIDWIDTH; j++)
		{
			if (array[i - 1][j - 1] == '*')
				neighbors++;
		}
	}
}
