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

#define GRIDWIDTH = 40;
#define GRIDHEIGHT = 20;
#define GENERATIONS = 2;

int main(int argc, char *argv[])
{
	char lifeGrid[GRIDWIDTH][GRIDHEIGHT][GENERATIONS];
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