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
//   Calls:		...
// 
//   Returns:	EXIT_SUCCESS (successful execution)
//				EXIT_FAILURE (unsuccessful execution)
//
//   History Log:
//                10/20/16	LMS	Version 1.0
// ------------------------------------------------------------------------------

int main(int argc, char *argv[])
{
	char lifeGrid[GENERATIONS][GRIDWIDTH][GRIDHEIGHT];
	int generationCounter = 0;
	int currentGeneration = 0;
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
				returnValue = EXIT_FAILURE;
			}
			else
			{
				//read(inFileHandle, lifeGrid)
				prompt = ' ';
			}
			break;
		case 'q':
		case 'Q':		//quit
			quit = 1;
			break;
		default:		//do next generation
			//calculate
			//print
			prompt = getch();
			break;
		}
	}
	return returnValue;
}