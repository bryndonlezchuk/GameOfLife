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
#include "life.h"
#include "ScreenPrinter.h"
#include "getNeighbors.h"
#pragma warning(disable: 4996)

#define GRIDWIDTH 40
#define GRIDHEIGHT 20
#define GENERATIONS 2

//------------------------------------------------------------------------------
//   Function:    main()
//
//   Title:       Game of Life
//
//   Description: 
//                Steps through generations in an array.
//
//   Programmer:  Lael Smith
//   
//   Date:        11/22/2016
// 
//   Version:     1.0
//  
//   Environment: Intel i5-6600 
//                Software:  OS: MS Windows 10  
//                Compiles under Microsoft Visual Studio.Net 2015
//
//   Input:		  ...
//   Output:      ...
//
//   Calls:		printToScreen()
//				read_data()
//				walkthrough()
// 
//   Returns:	EXIT_SUCCESS (successful execution)
//				EXIT_FAILURE (unsuccessful execution)
//
//   History Log:
//                11/22/16	LMS	Version 1.0
// ------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	char lifeGrid[GENERATIONS][GRIDHEIGHT][GRIDWIDTH];
	int generationCounter = 0;
	int currentGeneration = 0;
	int nextGeneration = 1;
	Life lifeName;

	//variables for files
	FILE * inFileHandle = NULL;
	char filenameInput[FILENAME_MAX] = "";

	//variables for main
	char prompt = 'n';
	int quit = 0;
	int returnValue = EXIT_SUCCESS;

	while (quit == 0)
	{
		switch (prompt)
		{
		case 'n':
		case 'N':		//new file

			if (argc > 1)
			{
				strncpy(filenameInput, argv[1], FILENAME_MAX);
			}
			else
			{
				puts("Enter the name of the file to read:");
				fgets(filenameInput, FILENAME_MAX, stdin);
				if (filenameInput[strlen(filenameInput) - 1] == '\n')
					filenameInput[strlen(filenameInput) - 1] = '\0';
				else
					while (getchar() != '\n')
						;
			}

			inFileHandle = fopen(filenameInput, "r");
			if (inFileHandle == NULL)
			{
				printf("Could not open file %s for input.\n"
					"Press any key to Continue", filenameInput);
				getch();
				quit = 1;
				returnValue = EXIT_FAILURE;
			}
			else
			{
				generationCounter = 0;
				currentGeneration = 0;
				read_data(inFileHandle, &lifeGrid[currentGeneration], currentGeneration, &lifeName);
				prompt = ' ';
			}
			break;
		case 'q':
		case 'Q':		//quit
			quit = 1;
			break;
		default:		//do next generation
			system("cls");
			printf("Generation: %d\n", generationCounter);										//header
			printToScreen(lifeGrid[currentGeneration], GRIDHEIGHT, GRIDWIDTH);					//print current generation
			prompt = getch();
			walkthrough(lifeGrid[currentGeneration], lifeGrid[(currentGeneration + 1) % 2]);	//step through to calculate next generation
			generationCounter += 1;
			currentGeneration = generationCounter % 2;
			break;
		}
	}
	return returnValue;
}