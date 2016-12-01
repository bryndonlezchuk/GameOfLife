#ifndef GET_NEIGHBORS_H
#define GET_NEIGHBORS_H
#include <stdio.h>
#pragma warning(disable: 4996)
#define ROWS 5
#define COLUMNS 5
#define DEAD '.'
#define ALIVE '*'

char isAlive(char array[ROWS][COLUMNS], int xcell, int ycell);
void getNeighbors(char array[ROWS][COLUMNS], int xcell, int ycell);

#endif

