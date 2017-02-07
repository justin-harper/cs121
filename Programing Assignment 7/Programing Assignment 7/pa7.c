#include "pa7.h"

int correctAnswers = 0, remainingAttemps = 3, correctThisLevel = 0;
char  initals[3];

void mathProgram (void)
{
	
	
	
	printf("Hello\n");
	menu();
	
	return;
}

void menu (void)
{
	int choice = 0, difficulty = 1;

	while(choice != 5 && remainingAttemps > 0)
	{
		system("cls");
		printf("Please choose from the following options:\n");
		printf("1) Print instructions\n");
		printf("2) Enter initals\n");
		printf("3) Choose dificulty\n");
		printf("4) Start a new sequence of problems\n");
		printf("5) Save and quit\n");

		scanf(" %d", &choice);

		system("cls");

		switch (choice)
		{
		case 1: printInstructions();
			break;
		case 2: getInitals();
			break;
		case 3: difficulty = getDifficulty();
			break;
		case 4: startSequence(difficulty);
			break;


		}

	}

	printf("You scored %d correct answers\n", correctAnswers);
	system("pause");
	system("cls");

	return;
}


void printInstructions(void)
{
	printf("instructions go here\n");


	system("pause");
	system("cls");

	return;
}

void getInitals(void)
{
	
	printf("please enter your initals (no spaces):\n");
	scanf("%s", initals);

	printf("Initials: %c %c %c\n", initals[0], initals[1], initals[2]);

	system("pause");

	system("cls");
	return;
}

int getDifficulty(void)
{
	int difficulty = 0;
	printf("Please choose the level of difficulty:\n");
	printf("1) level 1\n");
	printf("2) level 2\n");
	printf("3) level 3\n");
	printf("4) level 4\n");
	printf("5) level 5\n");
	
	scanf(" %d", &difficulty);

	system("cls");
	return difficulty;
}

void startSequence(int difficulty)
{
	switch (difficulty)
	{
	case 1: level1();
		break;
	case 2: level2();
		break;
	case 3: level3();
		break;
	case 4: level4();
		break;
	case 5: level5();
		break;
	default: printf("error\n");
		break;
	}


	return;
}

void level1 (void) //Easy: Includes addition and subtraction problems, with positive single digit operands and up to three terms only (i.e. d1 + d2 - d3  = )
{
	int terms = 0;
	
	remainingAttemps = 3;
	correctThisLevel = 0;
	printf("level 1\n");
	system("pause");

	while(remainingAttemps > 0 && correctThisLevel < 5)
	{
	
		terms = rand() % 2;
	
		if(terms == 0) //use only two terms for this question
		{
			addSub2Terms();
		}
		else //use three terms for this question
		{
			addSub3Terms();
		}

	}
	if( correctThisLevel >= 5) //move on to the next level
	{
		level2();
	}
	return;
}

void level2 (void) //Fair: Includes multiplication problems, with positive single digit operands and up to two terms only (i.e. d1 x d2 =  )
{
	remainingAttemps = 3;
	correctThisLevel = 0;
	printf("level 2\n");
	system("pause");

	while(remainingAttemps > 0 && correctThisLevel < 5)
	{
		multiply2Terms();
	}
	
	if(correctThisLevel >= 5)
	{
		level3();
	}

	return;
}

void level3 (void) //Intermediate: Includes division problems, with positive single digit operands and up to two terms only (i.e. d1 / d2 =  )
{
	remainingAttemps = 4;
	correctThisLevel = 0;
	printf("level 3\n");
	system("pause");

	while(remainingAttemps > 0 && correctThisLevel < 5)
	{
		divide2Terms();
	}
	
	if(correctThisLevel >= 5)
	{
		level4();
	}
	return;
}

void level4 (void) //Includes a mix of addition, subtraction, multiplication, and division problems, with positive single digit operands
{
	int random = 0;
	remainingAttemps = 4;
	correctThisLevel = 0;
	printf("level 4\n");
	system("pause");
	
	while(remainingAttemps > 0 && correctThisLevel < 5)
	{
		random = rand() %3 + 1;
		switch (random)
		{
		case 1: addSub3Terms();
			break;
		case 2: multiply2Terms();
			break;
		case 3: divide2Terms();
			break;
		}

	}
	
	if(correctThisLevel >= 5)
	{
		level5();
	}
	
	return;
}

void level5 (void) //Impossible: Includes a mix of addition, subtraction, multiplication, and division problems, with positive two and three digit operands and up to four terms only (i.e. dd1 + -ddd2 x ddd3 / dd4 = )
{
	remainingAttemps = 4;
	correctThisLevel = 0;

	printf("level 5\n");
	system("pause");
	
	while(remainingAttemps > 0 && correctThisLevel < 5)
	{
		goFor5();
	}
	
	if(correctThisLevel >= 5)
	{
		victoryFormation();
	}
	
	return;
}

void addSub2Terms(void)
{
	int x = 0, y = 0, operation = 0, answer = 0;
	
	
		operation =  rand() % 2;
		x = rand() % 9;
		y = rand() % 9;

		if (operation == 0) // add
		{
			printf("Please calculate %d + %d\n", x, y);
			scanf(" %d", &answer);

			check(answer, x+y);



		}
		else // subtract
		{
			printf("Please calculate %d - %d\n", x, y);
			scanf(" %d", &answer);

			check(answer, x-y);
		}
	

	return;
}

void addSub3Terms(void)
{
	int x = 0, y = 0, z = 0, operation = 0, answer = 0;
	
	
		operation =  rand() % 2;
		x = rand() % 9;
		y = rand() % 9;
		z = rand() % 9;

		if (operation == 0) // add
		{
			printf("Please calculate %d + %d + %d\n", x, y, z);
			scanf(" %d", &answer);

			check(answer, x+y+z);



		}
		else // subtract
		{
			printf("Please calculate %d - %d - %d\n", x, y, z);
			scanf(" %d", &answer);

			check(answer, x-y-z);
		}

	return;
}

void check (int userAnser, int rightAnswer)
{
	
	if(userAnser == rightAnswer)
	{
		printf("You're Right! :)\n");
		correctAnswers++;
		correctThisLevel++;
	}
	else
	{
		remainingAttemps--;
		printf("Sorry the correct anser is %d\n You have %d chances remaining\n", rightAnswer, remainingAttemps);
	
	}
	return;
}

void checkDiv (int userAnser, int userRemainder, int rightAnswer, int remainderAnswer)
{
	
	if(userAnser == rightAnswer && userRemainder == remainderAnswer)
	{
		printf("You're Right! :)\n");
		correctAnswers++;
		correctThisLevel++;
	}
	else
	{
		remainingAttemps--;
		printf("Sorry the correct anser is %d %d\n You have %d chances remaining\n",rightAnswer, remainderAnswer, remainingAttemps);
	
	}
	return;
}

void multiply2Terms(void)
{
	int x = 0, y = 0, answer = 0;

	x = rand() % 9;
	y = rand() % 9;

	printf("Please calculate %d * %d\n", x, y);
			scanf(" %d", &answer);

			check(answer, x*y);


	return;
}

void divide2Terms(void)
{

	int x = 0, y = 0, answer = 0, remainder = 0;

	x = rand() % 9;
	y = rand() % 8 + 1; //note can't divide by 0

	printf("Please calculate %d / %d\nNOTE: integer remainer", x, y);
	scanf(" %d %d", &answer, &remainder);

	checkDiv(answer, remainder, x/y, x%y);



	return;
}

//Impossible: Includes a mix of addition, subtraction, and multiplication problems, with positive two and three digit operands
//and up to four terms only (i.e. dd1 + -ddd2 x ddd3 / dd4 = )

void goFor5(void) 
{
	int op1 = 0, op2 = 0, op3 = 0; //randoms to determine opperations

	op1 = rand() % 9;

	switch (op1)
	{
		//(w + x + y + z)
	case 0:
		break;
		//(w - x - y - z)
	case 1:
		break;
		//(w * x * y * z)
	case 2:
		break;
		//(w + x - y + z)
	case 3:
		break;
		//(w + x + y - z)
	case 4:
		break;
		//(w + x + y * z)
	case 5:
		break;
		//(w - x + y + z)
	case 6:
		break;
		//(w - x - y + z)
	case 7:
		break;
		//(w - x - y * z)
	case 8:
		break;
		//(w * x + y + z)
	case 9:
		break;
		//(w * x - y - z)
	case 10:
		break;
		//(w * x + y * z)
	case 11:
		break;
		//(w * x * y + z)
	case 12:
		break;
		//(w * x * y - z)
	case 13:
		break;
		//(w * x - y * z)
	case 14:
		break;

		
	}

	

	return;
}








void victoryFormation(void)
{
	printf("you did it! ;)");
	return;
}