#include "Project4_Anthony.h"

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