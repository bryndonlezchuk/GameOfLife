#include <stdio.h>
#include <stdlib.h>
#include "getNeighbors.h"



int main(void)
{
	//testing a char array, not working so well
	printf("test with char array\n");
	char a1[5][5] = {
		{ '*',' ',' ',' ',' '},
		{ ' ','*',' ',' ',' ' },
		{ ' ',' ','*',' ',' ' },
		{ ' ',' ',' ',' ',' ' },
		{ ' ',' ',' ',' ',' ' },
	};
	putchar(a1[0][0]);  // outputting these to make sure they are alive/dead
	putchar(a1[1][1]);  //
	putchar(a1[2][2]);  // 
	putchar(a1[3][3]);  //
	putchar(a1[4][4]);  //
	putchar('\n');
	printf("%d\n", isAlive(a1, 0, 0));
	printf("%d\n", isAlive(a1, 1, 1));
	printf("%d\n", isAlive(a1, 2, 2));
	printf("%d\n", isAlive(a1, 3, 3));
	printf("%d\n", isAlive(a1, 4, 4));
	putchar('\n');

	//testing an int array, works properly
	printf("test with int array \n");
	int a2[5][5] = {
		{ 0, 0, 0, 0, 0 },
		{ 0, 1, 0, 0, 0 },
		{ 0, 0, 2, 0, 0 },
		{ 0, 0, 0, -1, 0 },
		{ 0, 0, 0, 0, 'a' },
	};
	printf("%d\n", isAlive(a2, 0, 0));
	printf("%d\n", isAlive(a2, 1, 1));
	printf("%d\n", isAlive(a2, 2, 2));
	printf("%d\n", isAlive(a2, 3, 3));
	printf("%d\n", isAlive(a2, 4, 4));

	getche();
	return EXIT_SUCCESS;
}
