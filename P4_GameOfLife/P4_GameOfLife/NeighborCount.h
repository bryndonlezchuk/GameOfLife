#ifndef NEIGHBORCOUNT_H
#define NEIGHBORCOUNT_H
#define ROWS 20
#define COLUMNS 40
#define DEAD 0
#define ALIVE 1
#define DEAD2 ' '
#define ALIVE2 '*'
#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable: 4996)

int isAlive(char array[ROWS][COLUMNS], int xcell, int ycell);
void getNeighbors(char array[ROWS][COLUMNS], int xcell, int ycell);

#endif
