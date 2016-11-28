//----------------------------------------------------------------------
// File: ScreenPrinter.h
//
// Functions: printToScreen( )
//----------------------------------------------------------------------

#ifndef SCREENPRINTER_H
#define SCREENPRINTER_H
#include <stdio.h>

void printToScreen(char *plane, int width, size_t totalNumberElements);
//void printToScreen(int height, int width, char plane[height][width]);

#endif // !SCREENPRINTER_H