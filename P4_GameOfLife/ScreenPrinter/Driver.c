#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../P4_GameOfLife/ScreenPrinter.h"
#pragma warning(disable: 4996)
#define xSIZE 5
#define ySIZE 3
#define zSIZE 2

int main(void)
{
	int rows = ySIZE;
	int cols = xSIZE;

	char a1[zSIZE][ySIZE][xSIZE] = {
		{
			{ '|', '+', '*', '+', '|' },
			{ '|', '+', '*', '+', '|' },
			{ '|', '+', '*', '+', '|' }
		},
		{
			{ '|', '-', '*', '-', '|' },
			{ '|', '-', '*', '-', '|' },
			{ '|', '-', '*', '-', '|' }
		}
	};
	printf("Screen printer test, press any key to continue");
	getche();

	system("cls");

	printf("a[0]:\n");
	printToScreen(a1[0], rows, cols);
	//printToScreen(ySIZE, xSIZE, a1);
	printf("a[1]:\n");
	printToScreen(a1[1], rows, cols);

	getche();
	return EXIT_SUCCESS;
}