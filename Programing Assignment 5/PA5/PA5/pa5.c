/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 5, version 0.1												 *
*																						 *
*		NOTE: this is part 1															 *
*																						 *
*	Description:																		 *
*	This program reads values from a file and											 *
*	answers to the following questions:													 *
*																						 *
*		Is the value a multiple of 7, 11, or 13?										 *
*		Is the sum of the digits odd or even?											 *
*		Is the value a prime number?													 *
*																						 *
******************************************************************************************

*/



#include "pa5.h"

#define NUMBERS 10


void computations (FILE * file) //this is the main function for this assignment (the real main should only be a simple funtion to start the magic)
{
	int value = -1;
	
	int factor = 0;

	while(!feof(file)) //continue until the end of the file.
	{
		//note if the last entry in the file is an empty line the previous line will be repeated

		factor = 0;
		readInt(file, &value);//get int from file
		if(value == -1)
		{
			printf("error\n");//-1 is an invalid entry which means something went wrong
		}
		else
		{
			if(value % 7 == 0) //check if value is a multiple of 7
			{
				
				factor = 1;
				printf("%d is a multiple of 7\n", value);

			}
			if(value % 11 == 0) //check if value is a multiple of 11
			{
				
				factor = 1;
				printf("%d is a multiple of 11\n", value);
			}
			if(value % 13 == 0) //check if value is a multiple of 13
			{
				printf("%d is a multiple of 13\n", value);
				factor = 1;
				
			}
			if(factor == 0)//if factor is 0 than value is not a multiple of 7 11 or 13
			{
				printf("%d is not a factor of 7, 11, or 13\n", value);
			}
			
			
			if(sumDigits(value) %2 == 0)//checks if the sum of the digits is even
			{
				printf("The sum of digits (%d) is even\n", value);
			}
			else
			{
				printf("The sum of digits (%d) is odd\n", value);
			}

			isPrime(value); //determines primeness ...if primeness is not a word than I just invented it...lol
		}

		

	}


}

FILE * openFileWrite(void)//open file for writing
{
	FILE * input = NULL;

	input = fopen("numbers.txt", "w");

	if(input == NULL)
	{
		printf("error\n");
		
	}

	return input;

}

FILE * openFileRead(void)//open file for reading
{
	FILE * input = NULL;

	input = fopen("numbers.txt", "r");

	if(input == NULL)
	{
		printf("error");
		
	}

	return input;

}

void fillFile (FILE * file)//fill file with NUMBERS(default 10) random numbers
{
	int i = 0;

	for(i = 0; i< NUMBERS; i++)
	{
		fprintf(file, "%d\n", (rand() % 50 + 1));
	}
}

void readInt (FILE * file, int *value)//read the int from the file
{
	

	fscanf(file, "%d", value);

	return;
}

int sumDigits(int num)//sum the digits of num
{
	int sum = 0;
	while (num != 0)
	{
		sum = sum + num %10;
		num = num / 10;
	}

	return sum;
}

void isPrime(int value)//determine primeness
{
		int check = 0;
		int prime = 0;
		int contin = 1;
		
		if(value == 1)
		{
			prime = 1;
			printf("%d is prime\n\n", value);
		}
		if(value == 2)
		{
			prime = 1;
			printf("%d is prime\n\n", value);
		}


		for(check = 2; (check < value - 1) && (contin); check++)
		{
			if(value % check == 0)
			{
				contin = 0;
				prime = 0;
				printf("%d is not prime\n\n", value);
			}
		}
		if(check == value - 1 && contin)
		{
			printf("%d is prime\n\n", value);
			prime = 1;
		}
		return;

}

