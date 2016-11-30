#define GEN_MIN	2
#define GEN		10
#define GEN_MAX 100
#define	ROW_MIN	2
#define	ROW		140
#define ROW_MAX	400
#define	COL_MIN	3
#define COL		200
#define COL_MAX	600

#define LIVE_SET "@$%&*#O0XLl"

// this struct should go into a header file 
struct Life {
	char name[80];
	int	 gen;		// generation or Z axis
	int	 row;		// Y 
	int	 col;		// X 
	char dead;		// character to use to show dead cell
	char live;		// character to use to show live cell
	int  version;
	int  delay;		// for game speed - 0 is the fastest
	int	 gens[GEN];
	int	 cells[GEN];
};


//-----------------------------------------------------------------------------
//	Function:		chrInStr()
//
//	Title:			Utility function for user input checking 
//
//	Description:	Given an user input character, this function will return TRUE 
//					if the character is in the string, and FALSE otherwise.
//
//	Programmer:		Janos Szamosfalvi
//
//	Date:			11/16/2016
//	Version:		1.0
//
//	Called by:		main()
//
//	Calls:			N/A
//
//	Parameters:		
//			ch:		char;	character to be checked against the string 
//			str:	char*	string of possible characters 
//
//	Returns:		TRUE if the character is in the string
//					FALSE otherwise 
//
//	History log:	11/16/2016	completed v1.0 for CS131
//-----------------------------------------------------------------------------

int chrinstr(char ch, const char* str)
{
	while (*str)
		if (ch == *str++)
			return TRUE;
	return FALSE;
}


//-----------------------------------------------------------------------------
//	Function:		read_data()
//
//	Title:			Function 
//
//	Description:	Given a file pointer to an open text file containing a header
//					and a textual image of a game of life pattern, this function  
//					will read in the 'life' image and the associated parameters. 
//
//	Programmer:		Janos Szamosfalvi
//
//	Date:			11/26/2016
//	Version:		1.0
//
//	Called by:		main()
//
//	Calls:			setLive()
//					setDead()
//					chrInStr()
//
//	Parameters:		
//		*fp:		FILE; pointer to an opened file containing a life pattern
//		arr:		pointer to 3D array contining the game of life world 
//		idx:		int; index into a 2D slice in the above 3D array
//		*life		Life: a structure containing various "life" variables 
//
//	History log:	11/26/2016	completed v1.0 for CS131
//-----------------------------------------------------------------------------


void read_data(FILE *fp, char arr[][ROW][COL], char idx, Life *life)
{
	int		num_result;
	int		chr_result; 
	char	*fg_result; 
	char	line[FILENAME_MAX];
	char	string[FILENAME_MAX];
	char	*pdest;
	char	ch; 
	int		number;
	int		found_end = FALSE; 
	int		i; 
	int		j; 

		
	do {
		fg_result = fgets(line, FILENAME_MAX, fp);

		if ((fg_result != NULL) && (line[0] != ';'))
		{
			pdest = strchr(line, ':');
			pdest++; 
			if (pdest != NULL)
			{
				num_result = sscanf(pdest, "%d", &number);	
				chr_result = sscanf(pdest, "%c", &ch);
				strcpy(string, pdest); 
			}
			else
			{
				number = 0;
				ch = '\0';
				string[0] = '\0'; 
			}

			if (strncmp(strupr(line), "ROW", strlen("ROW")) == 0)
			{
				if (number > ROW_MAX)
				{
					printf(COUNT_MAX_STR, "Row", number, ROW_MAX);
					printf(SET_TO_STR, "Row", ROW_MAX);
					number = ROW_MAX;
				}
				if (number < ROW_MIN)
				{
					printf(COUNT_MIN_STR, "Row", number, ROW_MIN);
					printf(SET_TO_STR, "Row", ROW_MIN);
					number = ROW_MIN;
				}
				life->row = number;
			}

			if (strncmp(strupr(line), "COL", strlen("COL")) == 0)
			{
				if (number > COL_MAX)
				{
					printf(COUNT_MAX_STR, "Column", number, COL_MAX);
					printf(SET_TO_STR, "Column", COL_MAX);
					number = COL_MAX;
				}
				if (number < COL_MIN)
				{
					printf(COUNT_MIN_STR, "Column", number, COL_MIN);
					printf(SET_TO_STR, "Column", COL_MIN);
					number = COL_MIN;
				} 
				life->col = number;
			}

			if (strncmp(strupr(line), "NAME", strlen("NAME")) == 0)
				strcpy(life->name, string);

			if (strncmp(strupr(line), "VER", strlen("VER")) == 0)
				life->version = number;

			if (strncmp(strupr(line), "DEAD", strlen("DEAD")) == 0)
				life->dead = ch;

			if (strncmp(strupr(line), "LIVE", strlen("LIVE")) == 0)
				life->live = ch;
			
			if (strncmp(strupr(line), "END", strlen("END")) == 0)
				found_end = TRUE;

		}	// end if 

	} while (!found_end);

	// this loop populates the first 2D plane 
	// if fgets() can't read any more data (most likely because of EOF), or a line has less 
	// data then required, this loop will populate the remainder of the array with dead cells then 
	for (i = 0; i < life->row; i++)
	{
		fg_result = fgets(line, FILENAME_MAX, fp);

		for (j = 0; j < life->col; j++) 
			if ((fg_result != NULL) && (j <= (int) strlen(line)))
				if (chrinstr(line[j], LIVE_SET)) 
					setLive(arr, idx, life, i, j); 
				else
					setDead(arr, idx, life, i, j);				
			else
				setDead(arr, idx, life, i, j);							

		line[0] = '\0'; 
	}

}	// end read_data()