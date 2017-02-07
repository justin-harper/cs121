#include "lab8.h"

#define SIZE 10

FILE * openFile(void)
{
	FILE * input = NULL;

	input = fopen("input.txt", "r");

	if(input == NULL)
	{
		printf("ERROR");
		
	}
	
	return input;

}

int part1 (void)
{
	FILE * input = NULL;
	int numbers [SIZE];
	int i = 0;

	input = openFile();

	for( i = 0; !feof(input); i++ )
	{
		fscanf(input,"%d", &numbers[i]);
		printf("numbers[%d]: %d\n", i, numbers[i]);
	}
	
	printf("\n");

	reverseArray(numbers);

	printArray(numbers);

	return 1;
}

void reverseArray (int num [SIZE])
{
	int end = SIZE - 1;
	int begin = 0;
	int toSwap = num[0];

	while(end > begin)
	{
		toSwap = num[begin];
		num[begin] = num[end];
		num[end] = toSwap;

		
		end--;
		begin++;


	}

}

void printArray(int a [SIZE])
{
	int i = 0;

	for ( i = 0; i < SIZE - 1; i++)
	{
		printf("array[%d]: %d\n", i, a[i]);
	}

return;
}


/*
2. Write a program that populates an array with 20 random integers between 1 - 100.
The program must traverse through the array and determine how many times each integer
was generated. Use a second array of size 101 to keep track of the number of times 
each integer was generated. Initialize each item in the second array to 0. For each
item in the first array, use it as the index into the second array and increment the
contents found in the second array at the corresponding index. Note: for this problem we
are willing to trade memory efficiency (the second array is mostly unused) for time efficiency.
We know indexing into an array is very efficient.
*/

void part2(void)
{
	int numbers [20];
	initArray(numbers);
	count(numbers);
}

void initArray(int numbers [])
{
	int i = 0;
	for(i=0; i < 20; i++)
	{
		numbers [i] = rand() % 100 + 1;
		printf("%d\n", numbers[i]);
	}
	return;
}

void count(int numbers [])
{
	int i = 0;
	int times [101] = {0};

	for(i=0; i<20; i++)
	{
		times[numbers[i]] += 1;
	}

	for(i = 0; i<100; i++)
	{
		printf("times[%d]: %d\n", i, times[i]);
	}

	return;
}



/*

3. Complete the following programming project 9 on p. 448 of your Hanly & Koffman Problem Solving and
Program Design in C text. Write an interactive program that plays a game of hangman. Store the word to
be guessed in successive elements of an array of individual characters called word (note: this is not 
a string!). The player must guess the letters belonging to word. The program should terminate when either
all letters have been guessed correctly (the player wins) or a specified number of incorrect guesses have
been made (the computer wins). Hint: use another array, guessed, to keep track of the solution so far. Initialize
all elements of guessed to the '*' symbol. Each time a letter in word is guessed, replace the corresponding
'*' in guessed with that letter.
*/

void part3(void)
{
	char word [26];
	char guessed [26];



	printf("Please enter a word");




}

