#include <stdio.h>
#include <stdlib.h>
#include "getNeighbors.h"



int main(void)
{
	//testing isAlive with 5 x 5 char array
	printf("test of isAlive()\n");
	char a1[5][5] = {
		{ '.', '.', '.', '.', '.' },
		{ '.', '*', '.', '.', '.' },
		{ '.', '.', '*', '.', '.' },
		{ '.', '.', '.', '*', '.' },
		{ '.', '.', '.', '.', '.' },
	};
	putchar(a1[0][0]);  // outputting these to make sure they are alive/dead
	putchar(a1[1][1]);  //
	putchar(a1[2][2]);  // 
	putchar(a1[3][3]);  //
	putchar(a1[4][4]);  //
	putchar('\n');
	printf("%c", isAlive(a1, 0, 0));
	printf("%c", isAlive(a1, 1, 1));
	printf("%c", isAlive(a1, 2, 2));
	printf("%c", isAlive(a1, 3, 3));
	printf("%c", isAlive(a1, 4, 4));
	putchar('\n');


	//testing getNeighbors with 5 x 5 array
	printf("test of getNeighbors\n");
	char a2[5][5] = {
		{ '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.' },
		{ '.', '*', '*', '*', '.' }, //only 3 cells alive in this row
		{ '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '.' },
	};
	putchar(a2[2][1]);  // outputting these to make sure all are live
	putchar(a2[2][2]);  // 
	putchar(a2[2][3]);  //
	putchar(a2[4][4]);  //
	putchar(' \n');
	putchar(' \n');

	//print the original array 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", a2[i][j]);
		}
		putchar('\n');
	}
	//call getNeighbors function on living cells
	getNeighbors(a2, 2, 1);
	putchar(a2[2][1]);
	getNeighbors(a2, 2, 2);
	putchar(a2[2][2]);
	getNeighbors(a2, 3, 3);
	putchar(a2[3][3]);
	
	putchar('\n');
	putchar('\n');

	// print new array 
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c", a2[i][j]);
		}
		putchar('\n');
	}


	getche();
	return EXIT_SUCCESS;
}