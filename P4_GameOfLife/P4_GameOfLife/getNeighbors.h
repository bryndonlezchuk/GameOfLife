#ifndef GET_NEIGHBORS_H
#define GET_NEIGHBORS_H
#include <stdio.h>
#pragma warning(disable: 4996)
#define ROWS 20
#define COLUMNS 40
#define DEAD '.'
#define ALIVE '*'

char isAlive(char array[ROWS][COLUMNS], int xcell, int ycell);
int getNeighbors(char array[ROWS][COLUMNS], int xcell, int ycell);

#endif

