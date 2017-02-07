#include "functions.h"

int maleOrFemale(void) // return 0 for male and 1 for female
{
	char input = '0';
	int gender = -1;
	printf("Please indicate if you are a male or female by entering \"m\" or \"f\": \n");
	scanf(" %c", &input);
	switch (input)
	{
	case 'm': gender = 0;
		break;
	case 'f': gender = 1;
		break;
	default:gender = -1;
		break;
		
	}
	return gender;

}

double getHeight(void)
{
	double height = 0.0;
	double ft = 0.0;
	printf("Please enter Height (ft in): \n");
	scanf(" %lf %lf", &ft, &height);

	height += (ft*12);
	return height;
}

double getWeight(void)
{
	double weight = 0.0;
	printf("Please enter weight: \n");
	scanf(" %lf", &weight);
	return weight;
}

double getAge(void)
{
	double age = 0.0;
	printf("Please enter your age: \n");
	scanf(" %lf", &age);
	return age;
}

double calculateBMR (int gender, double weight, double hInches, double age)
{
	double BMR = 0.0;
	
	if(gender == 0) // male
	{
		BMR = (66 + (6.23 * weight) + (12.7 * hInches) - (6.8 * age));
	}
	else //female
	{
		BMR = (655 + (4.35 * weight) + (4.7 * hInches) - (4.7 * age));
	}

	return BMR;

}

int getLifestyle (void)
{
	int choice = 0;
	printf("Please choose from the following list to describe your lifestyle\n");
	printf("1: Sedentary\n");
	printf("2: Low activity\n");
	printf("3: Moderate activity\n");
	printf("4: High activity\n");
	printf("5: Extra activity\n");
	scanf(" %d", &choice);

	return choice;
}

double calculateCalories (double BMR, int lifestyle)
{
	double calories = 0.0;
	switch (lifestyle)
	{
	case 1: calories = (BMR * 1.2);
		break;
	case 2: calories = (BMR * 1.375);
		break;
	case 3: calories = (BMR * 1.55);
		break;
	case 4: calories = (BMR * 1.725);
		break;
	case 5: calories = (BMR * 1.9);
		break;
	default: calories = -1.0;
		break;
	}	
	return calories;
}

int part1 (void)
{
	int gender = -1;
	double height = 0.0;
	double weight = 0.0;
	double age = 0.0;
	int lifestyle = 0;
	double BMR = 0.0;
	double calories = 0.0;

	printf("Hello\nThis program will help you calculate calories\n");
	gender = maleOrFemale();
	height = getHeight();
	weight = getWeight();
	lifestyle = getLifestyle();

	BMR = calculateBMR(gender, weight, height, age);
	printf("Your calculated BMR is: %.2lf\n", BMR);
	calories = calculateCalories(BMR, lifestyle);
	printf("To maintain current body weight you should consume %.2lf calories per day\n", calories);

	return 1;
}

int part2(void)
{
	int bouns = 0;
	int index = 0;
	char dolla = 36;
	printf("Hello\nThis program will help you calculate a professional baseball player's bonus\n");

	for(index = 1; index <8; index++)
	{
	bouns += printStuff(index);
	}

	printf("The player's bouns is: ");
	
	printf("%c%d\n",dolla, bouns);

	

	return 1;
}

int calcBonus(int question, char TF)
{
	int bonus = 0;
	if(TF == 'y' || TF =='Y')
	{
	
		switch (question)
		{
		
		case 2: bonus = 75000;
			break;
		case 3: bonus = 100000;
			break;
		case 4: bonus = 50000;
			break;
		case 5: bonus = 35000;
			break;
		case 1: //fall through
		case 6: 			
		case 7: bonus = 25000;
			break;
			
		}
	}

	return bonus;
}

int printStuff(int question)
{
	int bonus = 0;
	char TF = '\0';
	switch (question)
	{
	case 1: printf("Did the player make an All-Star Game apperance?\n");
		scanf(" %c",&TF); bonus = calcBonus(question, TF);
				break;
	case 2: printf("Was the player a regular season MVP?\n");
		scanf(" %c",&TF); bonus = calcBonus(question, TF);
				break;
	case 3: printf("Was the player a world series MVP?\n");
		scanf(" %c",&TF); bonus = calcBonus(question, TF);
				break;
	case 4: printf("Did the player recive the golden glove award?\n");
		scanf(" %c",&TF); bonus += calcBonus(question, TF);
				break;
	case 5: printf("Did the player recive the silver slugger award?\n");
		scanf(" %c",&TF); bonus += calcBonus(question, TF);
				break;
	case 6: printf("Was the player a homerun champ?\n");
		scanf(" %c",&TF); bonus += calcBonus(question, TF);
				break;
	case 7: printf("Was the player a batting average champ?\n");
		scanf(" %c",&TF); bonus += calcBonus(question, TF);
				break;
	}

	return bonus;

	
}

FILE * input_file(void)
{
	FILE * input_file = NULL;

	input_file = fopen("input.dat","r");
	return input_file;
}

int part3(void)
{
	FILE * input = input_file();
	int out  = 0;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	int index = 0;
	int choice = 0;
	/*double average = 0.0;
	int hiVal = 0;
	int lowVal = 0;*/

	double calcuated = 0.0;

	if (input == NULL)
	{
		printf("error exiting");
		return 1;
	}

	for(index = 1; index < 6; index++)
	{
		out = readInt(input);
		
		switch (index)
		{
			case 1: num1 = out;
				break;
			case 2: num2 = out;
				break;
			case 3: num3 = out;
				break;
			case 4: num4 = out;
				break;
			case 5: num5 = out;
				break;
		}

	}
	choice = printStuff2();

	switch (choice)
	{
	case 1: calcuated = calcAverage (num1, num2, num3,num4, num5);
				break;
	case 2: calcuated = calHiVal (num1, num2, num3,num4, num5);
				break;
	case 3: calcuated = calLowVal (num1, num2, num3,num4, num5);
				break;
	}

	printf("The calculated value is: %.lf\n",calcuated);

	return 1;
}


int readInt(FILE * infile)
{
	int number = 0;
	fscanf(infile, "%d", &number);

	return number;
}

int printStuff2(void)
{
	int dowhile = 1;
	int choice = 0;
	
	
	
	printf("Please choose from the following list\n");
	printf("1: Calculate Average\n");
	printf("2: Calculate High Value\n");
	printf("3: Calculate Low Value\n");	
	scanf(" %d", &choice);

	

	return choice;
}

double calcAverage (int num1, int num2, int num3, int num4, int num5)
{
	double average = 0.0;
	average = ((num1 + num2 + num3 + num4 + num5) / 5.0);
	
		return average;
}

int calHiVal (int num1, int num2, int num3, int num4, int num5)
{
	int numbers [5] = {num1, num2, num3, num4, num5};
	
	int value = 0;
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		if(numbers[i] > value)
		{
			value = numbers[i];
		}
	}
	return value;
}


int calLowVal (int num1, int num2, int num3, int num4, int num5)
{
	int numbers [5] = {num1, num2, num3, num4, num5};
	
	int value = num1;
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		if(numbers[i] < value)
		{
			value = numbers[i];
		}
	}
	return value;
}

