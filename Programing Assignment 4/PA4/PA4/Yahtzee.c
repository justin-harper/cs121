/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 4, version 0.1												 *
*																						 *
*	Description:																		 *
*	This program will let you play a game of Yahtzee									 *
*																						 *
******************************************************************************************

*/




#include "Yahtzee.h"

int startHere(void)//this function could be performed from main but I like it better here
{
	srand((unsigned int) time (NULL)); 
	
	menu1();
	
	return 1;
}

int menu1(void) //display the menu to the user
{
	int run = 1;
	int input = 0;
	
	do
	{
		system("cls");
		printf("Please choose from the following menu:\n");
		printf("1 Print game rules\n");
		printf("2 Play Yahtzee\n");
		printf("3 Exit\n");

		scanf(" %d", &input);

		switch (input)
		{
		default:
			break;
		case 1: system("cls"); printRules();
			break;
		case 2: system("cls"); playGame();
			break;
		case 3: run = 0; system("cls"); printf("Goodbye :(\n");
			break;
		}

		
		
	}
	while(run == 1);
}

int printRules()//print the rules of yahtzee to the user
{
//Trace was here Mr. Porfessor man/TA student. Shhhhhhhhhhhhhhhhh... Don't tell Justin ;)
	FILE * rules = NULL;
	char text = '/0'; 
	int i = 0;

	system("cls");
	rules = fopen("Rules.txt", "r");
	if(rules == NULL)
	{
		printf("error\n");
		return 1;
	}
	for (i = 0; (!feof(rules)); i++)
	{
		fscanf(rules, "%c", &text); 
		printf("%c", text);
	}

	printf("\n");
	printf("\n");

	system("pause");
	system("cls");
	
}


int playGame(void)// this is where most of the work is done
{
	int dice [5];
	int numberOfTimes [6];
	int i = 0;
	int points = 0;
	int points2 = 0;
	int tok = 0;
	int round = 1;
	
	for(round = 1; round < 14; round++)
	{

	printf("Begin Round %d\n", round);
	printf("Rolling Dice\n");
	system("pause");
	
	for(i = 0; i < 5;i++)
	{
	
		dice [i] = rollDice();
		printf("Dice %d: %d\n", (i+1), dice[i]);
	
		}

		
	
		sortDice(&dice[0], &dice[1], &dice[2], &dice[3], &dice[4], dice);

		for(i=0; i<6; i++)
		{
			numberOfTimes[i] = sumSameDice(i+1, dice);
			//printf("%d 's: %d\n", i+1, numberOfTimes[i]);
			/*if(numberOfTimes[i] == 3 || numberOfTimes[i] == 4)
			{
				threeOfAKind(dice, &points);
			}*/				
		}
	

		if(!fullHouse(numberOfTimes, &points))
		{
			for(i=0; i<6; i++)
			{
				if(numberOfTimes[i] == 3)
				{
					threeOfAKind(dice, &points, 3);
					tok = 1;
				}
				if(numberOfTimes[i] == 4)
				{
					threeOfAKind(dice, &points, 4);
						tok = 1;
				}
			}
			if(smallStright(dice, &points))
			{
				
			}
			else if(largeStright(dice, &points))
			{

			}
			else if(yahtzee(dice, &points))
			{

			}
			else if(!tok)
			{
			chance(dice, &points);
			}
		}

	

		//printf("points: %d\n", points);
	








		/*ones = sumSameDice(1, dice);
		twos = sumSameDice(2, dice);
		threes = sumSameDice(3, dice);
		fours = sumSameDice(4, dice);
		fives = sumSameDice(5, dice);
		sixes = sumSameDice(6, dice);

		printf("%d ones\n", ones);
		printf("%d twos\n", twos);
		printf("%d threes\n", threes);
		printf("%d fours\n", fours);
		printf("%d fives\n", fives);
		printf("%d sixes\n", sixes);*/

		printf("\n");
		points2 += points;
		printf("you have earned %d points!\n", points);
		printf("you have a total of %d points\n", points2);
		system("pause");
		system("cls");

		points2 += points;
		points = 0;
		tok = 0;
		
	}

	endGame(points2);




	return 1;
}

int rollDice ()//pretty simple use rand() to get a random "dice" roll based on the system time
{
	int i = 0;
	
	
	i = (rand() %6) + 1;

	return i;
}

int sortDice(int * die1, int * die2, int * die3, int * die4, int * die5, int dice [5]) // bubble sort the array of dice from lowest to highest
{
	
	int i = 0;
	int j = 0;

	int temp = -1;
	int min = dice[0];
	int max = dice[0];

	for(i =0; i<5; i++)
	{
		for(j = i; j<5;j++)
		{
			if(dice[i]> dice[j])
			{
				temp = dice[i];
				dice[i] = dice[j];
				dice[j] = temp;
			}
		}
	}

	/*printf("dice sorted\n");

	for(i=0;i<5;i++)
	{
		printf("%d\n", dice[i]);
	}*/

	
	*die1 = dice[0];
	*die2 = dice[1];
	*die3 = dice[2];
	*die4 = dice[3];
	*die5 = dice[4];
	
	
	
	
	return 1;
}

int sumSameDice(int value, int dice [])//sum up the number of dice with the same value
{
	int number = 0;
	int i = 0;

	for(i=0; i<5; i++)
	{
		if (dice[i] == value)
		{
			number++;
		}
	}
	
	return number;

}

void threeOfAKind(int dice [], int * points, int tof) // assign points if a three of a kind exits
{
	int i = 0;
	int pts = 0;

	for(i = 0; i < 5; i++)
	{
		pts += dice[i];
	}
	if(tof == 3)
	{
		printf("Three - of - A - Kind\n");
	}
	else
	{
		printf("Four - of - A - Kind\n");
	}
	*points = pts;
	return;
}

int fullHouse (int values [], int * points) // assign points if a full house exits
{
	int pair = 0;
	int tok = 0;
	int i = 0;
	int fh = 0;

	for(i=0; i<6; i++)
	{
		if (values[i] == 2)
		{
			pair = 1;
		}
		if(values[i] == 3)
		{
			tok = 1;
		}
	}
	if(tok == 1 && pair == 1)
	{
		printf("Full House\n");
		*points += 25;
		fh = 1;
	}
	return fh;
}

int count (int dice [], int lookingFor) // this is from Andy's example to determine a small straight
{
	int countOf = 0;
	if (dice[0] == lookingFor)
	{
		countOf++;
	}
	if (dice[1] == lookingFor)
	{
		countOf++;
	}
	if (dice[2] == lookingFor)
	{
		countOf++;
	}
	if (dice[3] == lookingFor)
	{
		countOf++;
	}
	if (dice[4] == lookingFor)
	{
		countOf++;
	}
	return countOf;

}


int smallStright(int dice[], int * points) // assign points if a small straight exits
{
	int i = 0;
	int result = 0;
	int pts = 0;
	int isSS = 0;
	
	for(i = 0; i< 6; i++)
	{
		if (count(dice, i+1) >=1)
		{
			result +=1;
		}
		else
		{
			result = 0;
		}
	}

	if (result >= 4)
	{
		printf("Small Stright\n");
		pts = 30;
		isSS = 1;
	}

	*points += pts;
	
	/*if((dice[0] == 1 && dice[1] == 2 && dice[2] == 3 && dice[3] == 4) ||(dice[0] == 2 && dice[1] == 3 && dice[2] == 4 && dice[3] == 5) || (dice[1] == 4*/
	return isSS;
}

int largeStright(int dice [], int * points) // assign points if a large stright exits
{
	int pts = 0;
	int isLS = 0;
	if((dice[0] == 1 && dice[1] == 2 && dice[2] == 3 && dice[3] == 4 && dice[4] == 5) ||(dice[0] == 2 && dice[1] == 3 && dice[2] == 4 && dice[3] == 5 && dice[4] == 6))
	{
		printf("Large Stright\n");
		pts = 40;
		isLS = 1;
	}

	*points += pts;
	return isLS;
}

int yahtzee (int dice [], int * points) // winner winner chicken dinner! YAHTZEE
{
	int pts = 0;
	int isYZ = 0;

	if(dice[0] == dice[1] && dice[0] == dice[2] && dice[0] == dice[3] && dice[0] == dice[4])
	{
		printf("YAHTZEE\n");
		pts = 50;
		isYZ = 1;
	}

	*points += pts;
	return isYZ;
}

void chance (int dice [], int * points) // catchall to assing points for the round
{
	
	
	int i = 0;
	int pts = 0;

	printf("Chance\n");

	for(i = 0; i< 5; i++)
	{
		pts += dice[i];
	}

	*points += pts;
	return;
}

void endGame(int points) //positve reinfocement keeps 'em commin back
{
		printf("\n\n");   
	
	printf("                              JJJJJJJJ\n");
    printf("       JJJJJJJJ                  JJJJJJJJ\n");
    printf("      JJJJJJJJJJ                   JJJJJJJJ\n");
    printf("     JJJJJJJJJJJJ                    JJJJJJJJ\n");
    printf("     JJJJJJJJJJJJJ                     JJJJJJJJJ\n");
    printf("     JJJJJJJJJJJJJ                       JJJJJJJJ\n");
    printf("      JJJJJJJJJJJ                          JJJJJJJJ\n");
    printf("       JJJJJJJJJ     JJJJJJJJJJJ             JJJJJJJ\n");
    printf("                     JJJJJJJJJJJ              JJJJJJ\n");
    printf("                     JJJJJJJJJJJ              JJJJJJ\n");
    printf("       JJJJJJJJJ                              JJJJJJ\n");
    printf("      JJJJJJJJJJJ                            JJJJJJJ\n");
    printf("     JJJJJJJJJJJJJ                         JJJJJJJJ\n");
    printf("     JJJJJJJJJJJJJ                       JJJJJJJ\n");
    printf("     JJJJJJJJJJJJJ                     JJJJJJJJ\n");
    printf("      JJJJJJJJJJJ                    JJJJJJJJ\n");
    printf("       JJJJJJJJJ                   JJJJJJJJJ\n");
    printf("                                 JJJJJJJJJJ\n");

	printf("\n\n\n");

	printf("You scored a total of %d points, WAY TO GO! ;)\n", points);
	system("pause");
	return;
}