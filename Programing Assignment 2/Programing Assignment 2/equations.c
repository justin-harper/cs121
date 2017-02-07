/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 2, version 2.0												 *
*																						 *
*	Description:																		 *
*	This program will prompt the user for inputs to some equations and evaluate			 *
*	the equations based on the inputs.													 *
*	This program has some input validation and divide by 0								 *
*	validation, still be sure input is clean!											 *
*																						 *
******************************************************************************************

*/


#include "equations.h"



int startHere ()
{	/*
	**********************************************************************
	* This function will display a menu for the user to choose which	 *
	* forumal they want to use. this menu will also be shown			 *
	* after the formula is solved so the user may choose to				 *
	* solve another one													 *
	**********************************************************************
	*/
	int check = 1;

	while(check == 1)
	{
		int choice = 0;
	
		printf("Please choose from the following list of choices:\n");
		printf("1: Newton\'s Seccond Law F=MA\n");
		printf("2: Volume of a Cylinder\n");
		printf("3: Encode a Character\n");
		printf("4: Distance Between 2 Points\n");
		printf("5: Calculate the Tangent of an angle\n");
		printf("6: Calculate Equivilent Parallel Resistance\n");
		printf("7: Solve a general equation: y = (7 / 10) - z +x / (a % 2) + PI\n");
		printf("8: Exit\n");
		scanf("%d", &choice);
		printf("\n\n");

		switch (choice)		//ooo crazy I know :)	
		{
		default: jurassicParkFTW(); pressAnyKey();
				continue;
			
			case 1: newton(); pressAnyKey();
				break;
			
			case 2: volume(); pressAnyKey();
				break;
			
			case 3: encodeChar(); pressAnyKey();
				break;
			
			case 4: distance(); pressAnyKey();
				break;
			
			case 5: tan1(); pressAnyKey();
				break;
			
			case 6: resistance(); pressAnyKey();
				break;
			
			case 7: genEqn(); pressAnyKey();
				break;
			
			case 8: check = 0; printf("BYE ;(\n\n");
				break;		
		}
	}
	
	return 0;
}

double newtonII (double mass, double acceleration)
{
	/*
	This function will calculate the force given mass and acceleration
	*/

	// Force = mass * acceleration

	return mass * acceleration;	
}

int newton ()
{
	/*
	This function will prompt the user for input to get mass and accleration for
	Newton's seccond law of motion
	*/

	double mass = 0.0;
	double acceleration = 0.0;
	
	printf("Newtons seccond law of motion states: Force = Mass * Acceleration\n");
	
	printf("Please enter Mass and accelertion (decimals are OK) seperated by a space\n");
	scanf("%lf" "%lf", &mass, &acceleration);

	printf("Force = %.2lf [newtons]\n\n", newtonII(mass, acceleration));

	return 0;
}

double volumeCylinder (double radius, double height)
{ 
	/*
	This function will calculate the volume of a cylinder using:
	Volume of a cylinder = PI * R^2 * Height
	*/
	return (PI * pow(radius, 2) * height);
}

int volume()
{
	/*
	This function will prompt the user for radius and height of a cylinder
	*/
	
	double radius = 0.0;
	double height = 0.0;
	
	printf("The volume of a cylinder = PI * R^2 * height\nPlease enter the radius and height of the cylinder (decimals are OK) seperated by a space\n");
	scanf("%lf %lf", &radius, &height);

	printf("Volume = %.2lf\n\n", volumeCylinder(radius, height));
}

int encodeChar ()
{	
	/*
	This is the function we defined in class
	prompt user for a character and a value to "shift" then 
	display the "encoded" character
	*/
	int shift = 0;
	char my_char = '\0';
	char plantext_char = '\0';
	
	printf("Please enter a plain text character\n");
	scanf(" %c", &plantext_char);

	printf("Please enter number to \"shift\"\n");
	scanf("%d", &shift);

	my_char = plantext_char -'A' +'a'+ shift;

	printf("encoded char: %c\n\n", my_char);

	return 0;
}

double distance2Pts (double x1, double y1, double x2, double y2)
{ 
	/*
	This function will calculate distance between 2 points using:
	Distance = square root of ((x2-x1)^2 + (y2-y1)^2)
	*/

	double xSquared = 0.0;
	double ySquared = 0.0;
	double distance = 0.0;

	xSquared = pow((x2-x1),2);
	ySquared = pow((y2-y1),2);

	distance = sqrt(xSquared + ySquared);
	
	return distance;
}

int distance ()
{
	/*
	This function gets input from the user for the distance formula
	*/
	double x1 = 0, y1 = 0, x2 = 0, y2 = 0;
	
	printf("The distance between 2 points = square root of ((x2-x1)^2 + (y2-y1)^2)\nPlease enter x1 & y1 seperated by a space (decimals are OK)\n");
	scanf("%lf %lf", &x1, &y1);
	
	printf("Please enter x2 & y2 seperated by a space (decimals are OK)\n");
	scanf("%lf %lf", &x2, &y2);

	printf("The distance between (%.2lf,%.2lf) and (%.2lf, %.2lf) is:\n%.2lf\n\n", x1, y1, x2, y2, distance2Pts(x1,y1,x2,y2));

	return 0;
}

double myTangent (double theta)
{   /*
	This function calculates the tangent of theta using:
	Tangent(theta) = Sin(theta)/Cos(theta)
	
	*********************************************************
	*Note sin() and cos() compute the angle in radians		*
	*********************************************************
	
	*/
	
	double mytan = sin(theta) / cos(theta);
	
	return mytan;
}

int tan1 ()
{
	/*
	This function gets input from the user for calculating the tangent of theta (in radians)
	*/

	double theta = 0.0; 
	printf("Tangent(theta) = Sin(theta) / Cos(theta)\nPlease enter theta in radians (decimal is OK)\n");
	scanf("%lf", &theta);

	printf("Tangent of teta = %.2lf\n\n", myTangent(theta));
	return 0;
}

double equivilentParallelResistance (double R1, double R2, double R3)
{
	//Equivilent paralel resistance = 1/((1/R1)+(1/R2)+(1/R3))

	return (1 / ((1/R1)+(1/(R2)+(1/R3))));
}

int resistance ()
{
	/*
	This function gets input from the user for the equivilent parallel resitance formula
	*/
	double R1 = 0.0, R2 = 0.0, R3 = 0.0;
	int i = 0; //used for counting
	do
	{
		printf("Equivilent paralel resistance = 1/((1/R1)+(1/R2)+(1/R3))\nPlease enter R1, R2, R3 seperated by a space\n");
		scanf("%lf %lf %lf", &R1, &R2, &R3);
	} while ((R1 == 0.0 || R2 == 0.0 || R3 == 0.0) && i < 5);
	if(i == 5)
	{
		return 0;
	}
	else
	{
		printf("The equivilent parallel resistance is: %.2lf [ohms]\n\n", equivilentParallelResistance(R1, R2, R3));
	
		return 0;
	}
}

double generalEqn (double x,double y, double z, int a)
{
	/*
	This function solves the given general equation for "y"
	
	General Equation given is y = (7 / 10) - (y * z) + x / (a % 2) + PI
	******************************************************
	* Note if "a" is even a divide by 0 error will occur *
	******************************************************
	*/
	
	double posibleAns = 0.0;
	double const1 = (double) 7 / 10;
	
	posibleAns = (const1 - (y * z) + (x / (a % 2)));

	return posibleAns;	
}

int genEqn ()
{
	/*
	This function gets input form the user for use in the given general equation:
	y = (7 / 10) - (y * z) + x / (a % 2) + PI

	***************************************
	* Note there is some input validation *
	* however, make sure input is clean   *
	***************************************
	
	*/
	
	double x = 0, z = 0, y = 0;
	int j = 0, a = 0;
	int chances = 5;
	/*  if the user can't figure out that "a" needs to be odd in 5 attemps
		they are returned to the main menu
	*/
	
	do
	{
		//ooo a do while loop...fancy
		if(j > 0)
		{
			/*this message only shows if an invaid attempt has been made*/
		
			printf("\"a\" cannot be an even number\nPlease try again, you have %d chance(s) remaining\n\n\n", chances-j);			
		}
				
		printf("The general equation given is y = (7 / 10) - (y * z) + x / (a % 2) + PI\nPlease enter a x y & z seperated by a space\n");
		scanf("%d %lf %lf %lf", &a, &x, &y, &z);
		
		j++;
	
	} while ((a % 2 == 0) && j < chances);

	if (j == chances)
	{//this is where the user is returned to the main menu if they can't figure it out
		printf("Sorry you are having trouble better luck next time :)\n\n\n");
		return 0;
	}
	else
	{ //input is good lets solve the equation
		
		y = generalEqn(x,y,z,a);
		printf("y = %.2lf\n\n",y);
		return 0;
	}

}

int jurassicParkFTW()
{
	/*  Gotta have a little fun!
		Easter egg time :) 
	*/
	int i=0;
	for(i = 0; i<50; i++)
	{
		 printf("Ah ah ah you didn't say the magic word...\n");
	}
	printf("\n\n");
	printf("Please! GOD DAMN IT! ... I hate this hacker crap!\n");
	printf("\nTry to get it right this time :)\n\n");
	
	return 0;
}

int pressAnyKey ()
{
	/*
	This function waits for the user to enter a key before returning them to the menu
	I used char because there isn't any easy way to get the "press any key to continue"
	prompt so the user can enter any key followed by enter to continue
	*/
	char c = '\0';
	printf("1: Continue\n");
	scanf(" %c",&c);
	printf("\n\n");
	return 0;

}