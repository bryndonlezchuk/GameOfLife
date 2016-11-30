#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../P4_GameOfLife/ScreenPrinter.h"
#pragma warning(disable: 4996)
#define xSIZE 5
#define ySIZE 3

int main(void)
{
	int rows = ySIZE;
	int cols = xSIZE;

	char a1[ySIZE][xSIZE] = {
		{'|', ' ', '*', ' ', '|'},
		{ '|', ' ', '*', ' ', '|' },
		//{' ', '*', ' '},
		{ '|', ' ', '*', ' ', '|' }
	};
	printf("Screen printer test, press any key to continue");
	getche();

	printToScreen(a1, rows, cols);
	//printToScreen(ySIZE, xSIZE, a1);

	getche();
	return EXIT_SUCCESS;
}