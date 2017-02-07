#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{

	int num;
	int deno;

}fraction;




void part1(void);

int palindrome (char a [], int left, int right);

int numChar (char a []);

//void removeSpaces (char a [], char * x);

void part2(void);

void printMaze (char maze[8][8]);

int traverse(char maze[8][8], int row, int coll);

void structure (void);

void printFraction(fraction x);
