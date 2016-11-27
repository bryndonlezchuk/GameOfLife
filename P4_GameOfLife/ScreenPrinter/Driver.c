#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "../P4_GameOfLife/ScreenPrinter.h"
#pragma warning(disable: 4996)
#define xSIZE 3
#define ySIZE 3

int main(void)
{
	char a1[xSIZE][ySIZE] = {
		{' ', '*', ' '}
		{' ', '*', ' '}
		{' ', '*', ' '}
	};
	printf("Screen printer test, press any key to continue");
	getche();

	printToScreen(ySIZE, xSIZE, a1);

	getche();
	return EXIT_SUCCESS;
}