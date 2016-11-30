void walkthrough(char current[GRIDHEIGHT][GRIDWIDTH], char next[GRIDHEIGHT][GRIDWIDTH])
{
	int x = GRIDHEIGHT, y = GRIDWIDTH;
	int i = 0, j = 0;
	for (i = 0; i < y; i++)
		for (j = 0; j < x; j++)
		{
			if /*isalive*/ (current[x][y])
				next[y][x] = "*";
			else
				next[y][x] = " ";
		}
}