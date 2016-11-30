#ifndef LIFE_H
#define LIFE_H

// global defines
#define TRUE	1
#define FALSE	0

#define GEN_MIN	2
#define GEN		10
#define GEN_MAX 100
#define	ROW_MIN	2
#define	ROW		140
#define ROW_MAX	400
#define	COL_MIN	3
#define COL		200
#define COL_MAX	600

#define NUL		'\000'
#define BELL	'\007'
#define BS		'\010'
#define TAB		'\011'
#define LF		'\012'
#define CR		'\015'
#define DEL		'\177'


#define DEAD	'.'
#define DEAD2	','
#define	LIVE	'*'
#define	LIVE2	'#'
#define	LIVE3	'@'


#define LIVE_SET "@$%&*#O0XLl"
#define DEAD_SET ". ,_`"

#define COUNT_MIN_STR "%s count of %d is less than minimum of %d!\n"
#define COUNT_MAX_STR "%s count of %d is more than maximum of %d!\n"
#define SET_TO_STR	  "%s count is set to %d!\n\n"	

struct Life {
	char name[64];
	int	 gen;		// generation or Z 
	int	 row;		// Y 
	int	 col;		// X 
	char dead;		// character to show dead cell
	char live;		// character to use for a live cell
	int  version;
	int  delay;		// for game speed - 0 is the fastest
	int	 gens[GEN];
	int	 cells[GEN];
};
typedef struct Life Life;

void read_data(FILE *fp, char arr[][ROW][COL], char idx, Life *life);


#endif LIFE_H
