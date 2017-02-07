#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int moves = 0;

void part2(void);

int recSumDigits (int num);

void part3(void);

int getLength (char a []);

void recRevString (char a []);

void part4 (void);

void moveTower(int disk, int source, int dest, int spare);


//typedef struct
//{
//	int size;
//}disk;


int main (void)
{
	part4();

	

	return 0;
}

void part2 (void)
{
	//Write a function which returns the sum of the digits of an integer value. 
	//You must use recursion. Example sum (765) = 18, sum (16978) = 31, etc.

	int num = 0;
	int sum = 0;
	int x = 0;


	
	printf("please enter a number:\n");
	scanf(" %d", &num);

	x = num % 10;

	sum = recSumDigits(num);
	//printf("mod: %d\n", num % 10);
	//printf("mod: %d\n", x);

	//
	printf("sum: %d\n", sum);

	return;

}

int recSumDigits (int num)
{
	int sum = 0;
	int x = num % 10;
	if(num > 0)
	{
		x = num %10;
		sum += x;
		sum += recSumDigits(num / 10);


	}
	else
	{
	
		return sum;
	}
}


void part3(void)
{
   //Write a function which recursively reverses a string.

	char a [50] = "";
	

	printf("please enter a simple string:\n");
	scanf("%s", a);

	//printf("you entered: %s\n", a);



	
	printf("the string reversed is:\n");

	recRevString(a);

	printf("\n");
	return;

}

int getLength (char a [])
{
	int length = 0;
	int i = 0;
	while (a[i] != '\0')
	{
		length++;
		i++;
	}


	return length;
}

void recRevString (char a [])
{
	
	

	if(*a)
	{
		recRevString(a + 1);
		printf("%c", *a);
	}

}


void part4 (void)
{
// tower of Hanoi

//	FUNCTION MoveTower(disk, source, dest, spare):
//IF disk == 0, THEN:
//    move disk from source to dest
//ELSE:
//    MoveTower(disk - 1, source, spare, dest)   // Step 1 above
//    move disk from source to dest              // Step 2 above
//    MoveTower(disk - 1, spare, dest, source)   // Step 3 above
//END IF

	int disks = 0;
	printf("Tower of Hanoi \nplease enter number of disks:\n");

	scanf(" %d", &disks);

	system("cls");

	if(disks <= 20)
	{
	moveTower(disks, 1, 3, 2);

	printf("moves: %d\n", moves);
	}

	else
	{
		printf("are you fucking high?\n");
	}

	return;


}

void moveTower(int disk, int source, int dest, int spare)
{
	if(disk == 1)
	{
		printf("Move disk 1 from tower %d to tower %d\n", source, dest);
		moves++;
	}
	else
	{
		moveTower(disk - 1, source, spare, dest);
		printf("Move disk %d from tower %d to tower %d\n", disk, source, dest);
		moves++;
		moveTower(disk - 1, spare, dest, source);
	}

	return;

}