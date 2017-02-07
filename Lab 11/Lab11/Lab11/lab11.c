#include "lab11.h"



void printFraction(fraction x)
{
	printf("%d / %d\n", x.num, x.deno);
}

void structure (void)
{
	fraction myfrac;

	myfrac.num = 13;
	myfrac.deno = 15;

	printFraction(myfrac);
}



void part1(void)
{
	char w1 [] = {"level"}; //w2 [] = {"deed"}, w3 [] = {"sees"}, w4 [] = {"Madam Im Adam"}, w5 [] = {"not"};
	//char w42[50];

	int last = numChar(w1) -1;

	/*removeSpaces(w4, w42);


	printf("%s\n", w42);*/

	int tof = palindrome(w1, 0, last );
	
	printf("palindrome? %d\n", tof);

	return;
}

int numChar (char a [])
{
	int i = 0;
	int num = 0;
	while(a[i] != '\0')
	{
		num++; i++;
	}
	return num;
}

int palindrome (char a [], int left, int right)
{
	int x = 0;
	
	if(left >= right)
	{
		if(a[left] == a[right])
		{
			x = 1;
		}
	}
	else
	{
		x = palindrome(a, left + 1, right - 1);
	}
	return x;
}

//void removeSpaces (char a [], char * x)
//{
//	int l = numChar(a)-1;
//	int i = 0;
//	int index = 0;
//	char b [50];
//	while (i < l)
//	{
//		if(a[i] == ' ')
//		{
//			
//		}
//		else
//		{
//			b[index] = a[i];
//			index++;
//		}
//		i++;
//	}
//	
//	x = b;
//
//}

void part2(void)
{
	int i=0, j=0;
	int madeIt = 0;


	     			  //  0    1    2    3    4    5    6    7
	char maze [][8] = { {' ', ' ', 'x', 'x', ' ', 'x', ' ', 'x'},//0 
					    {'x', 'x', ' ', 'x', ' ', 'x', 'x', ' '},//1
					    {' ', 'x', ' ', ' ', 'x', 'x', ' ', ' '},//2 
				        {'x', ' ', 'x', ' ', 'x', ' ', 'x', 'x'},//3
					    {'x', ' ', 'x', ' ', ' ', 'x', ' ', ' '},//4
					    {' ', 'x', ' ', 'x', ' ', ' ', 'x', 'x'},//5
					    {'x', ' ', 'x', 'x', ' ', ' ', ' ', ' '},//6
					    {'x', ' ', 'x', 'x', 'x', 'x', ' ', ' '} //7
																}; 

	

	printMaze(maze);

	
	madeIt = traverse(maze, 0, 0);

	if(madeIt == -1)
	{
		printf("no path\n");
	}
	else
	{
		printf("ain't nobody got time for this\n");
	}



}




void printMaze (char maze[8][8])
{
	int i=0, j=0;
	printf("0 1 2 3 4 5 6 7\n");

	for(i=0; i<8; i++)
	{
		for(j=0; j<8; j++)
		{
			printf("%c ", maze[i][j]);
		}
		printf("%d\n", i);
	}
}

int traverse(char maze[8][8], int row, int coll)
{  //row, coll
	
	int madeIt = 0;
	
	if(row == 7 && coll == 7)
	{
		madeIt = 1;
	}
	else
	{
		if(coll !=7)
		{
			if(maze[row][coll +1] !='x')
			{
				madeIt = traverse(maze, row, coll +1);
			}
			else
			{
				if(maze[row+1][coll] !='x')
				{
					madeIt = traverse(maze, row+1, coll);
				}
				else
				{
					madeIt = -1;
				}
			}
		}
		
	}

	return madeIt;


}