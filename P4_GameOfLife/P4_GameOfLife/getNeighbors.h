#ifndef GET_NEIGHBORS_H
#define GET_NEIGHBORS_H
#include <stdio.h>
#pragma warning(disable: 4996)
#define ROWS 25
#define COLUMNS 40
#define DEAD 0
#define ALIVE 1

int isAlive(int array[ROWS][COLUMNS], int xcell, int ycell);
void getNeighbors(int array[ROWS][COLUMNS], int xcell, int ycell);

#endif
