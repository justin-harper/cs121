/*
* Name: Justin Harper
* Lab2
*
*/

#include <stdio.h>
#include <math.h>

/*
function prototypes
*/

int part1 ();

double getX (int xn); //xn is for counting which point you are getting

double getY (int yn);

double computeSlope (double x1, double y1, double x2, double y2);

double computeMidPointX (double x1, double x2);

double computeMidPointY (double y1, double y2);

double computePerpendicularSlope (double slope);

double computeYIntercept (double slope, double xmid, double ymid);

int displayStuff (double slope, double midX, double midY, double yIntercept, double perpendicularSlope);

int part2();

double getHeight();

double getLbs();
 
double calculateBMI(double weight, double height);

int displayStuff2(double bmi);

int part3();

double getHarris ();

double getCoaches ();

double getComputer ();



int main(void)
{
	//part1();
	//part2();
	part3();
}

int part1 ()
{		
	
		double x1 = 0.0;
		double y1 = 0.0;
		double x2 = 0.0;
		double y2 = 0.0;
		
		double slope = 0.0;
		
		double midX = 0.0;
		double midY= 0.0;
		
		double perpSlope = 0.0;

		double yIntercept = 0.0;
	
		printf("\t\t\t Hello\nThis program will help you with some math operations:\n\n");
		printf("1: Compute slope of a line\n");
		printf("2: Compute midpoint between the 2 points\n");
		printf("3: Compute the perpendicular slope\n");
		printf("4: Compute the y intercept of the line\n");
		printf("\n\n");

		
		x1 = getX (1);
		y1 = getY (1);
		x2 = getX (2);
		y2 = getY (2);

		printf("\n\n\n");
		
		slope = computeSlope (x1,y1,x2,y2);

		midX = computeMidPointX (x1,x2);
		midY = computeMidPointY (y1,y2);

		perpSlope = computePerpendicularSlope (slope);

		yIntercept = computeYIntercept(slope, midX, midY);

		displayStuff(slope, midX, midY, yIntercept, perpSlope);
		

		
	
	return 0;
}

double getX (int xn) //xn is for counting which point you are getting
{
	int index = xn;
	double x = 0.0;
	printf("Please enter a value for x(%d):\n",index);
	scanf(" %lf", &x);

	return x;
}

double getY (int yn)
{
	int index = yn;
	double y = 0.0;
	printf("Please enter a value for y(%d):\n",index);
	scanf(" %lf", &y);
	return y;
}

double computeSlope (double x1, double y1, double x2, double y2)
{
	return ((y2-y1) / (x2 - x1));

}

double computeMidPointX (double x1, double x2)
{
	return ((x1+x2)/2);

}

double computeMidPointY (double y1, double y2)
{
	return ((y1+y2)/2);
}

double computePerpendicularSlope (double slope)
{
	return (-1*(1/slope));
}

double computeYIntercept (double slope, double xmid, double ymid)
{
	return (ymid - (slope * xmid));
}

int displayStuff (double slope, double midX, double midY, double yIntercept, double perpendicularSlope)
{
	printf("The Slope of the line is:\n%.2lf\n",slope);
	printf("the Midpoint is:\n(%.2lf, %.2lf)\n", midX, midY);
	printf("The y intercept is:\n%.2lf\n",yIntercept);
	printf("The perpendicular slope of the line is:\n%.2lf\n",perpendicularSlope);
	printf("the y=mx+b formula is:\ny = %.2lf(x) + %.2lf\n", slope, yIntercept);

	return 0;
}

int part2()
{
	double weight = 0.0;
	double height = 0.0;
	double bmi = 0.0;
	printf("\t\t\t Hello\nThis program will help you calculate your BMI\n\n");

	weight = getLbs();
	height = getHeight();

	bmi = calculateBMI(weight, height);

	
	
	displayStuff2(bmi);



	return 0;
}

double getLbs()
{
	double weight = 0.0;
	printf("Please enter your weight in lbs:\n");
	scanf("%lf", &weight);
	return weight;
}

double getHeight()
{
	double heightFT = 0.0;
	double heightIN = 0.0;
	printf("Please enter your height in the following format \"FT IN\":\n");
	scanf("%lf %lf", &heightFT, &heightIN);

	heightIN += (heightFT * 12);

	return heightIN;

}

double calculateBMI(double weight, double height)
{
	if(height !=0.0)
	{
	return ((weight / pow(height,2))*703);
	}
	else
	{
		printf("Can't divide by 0");
	}
}

int displayStuff2(double bmi)
{
	if (bmi <= 18)
	{
		printf("Your BMI is: %.2lf\nYou are underweight\n",bmi);
	}
	if(bmi > 18 && bmi < 25)
	{
		printf("Your BMI is: %.2lf\nYou are at a heathy weight\n",bmi);
	}
	if(bmi >= 25 && bmi < 30)
	{
		printf("Your BMI is: %.2lf\nYou are overweight\n",bmi);
	}
	if(bmi >= 30)
	{
		printf("Your BMI is: %.2lf\nYou are obease\n",bmi);
	}
		
	return 0;
}

int part3()
{
	double harris = 0.0;
	double coaches = 0.0;
	double computerRank = 0.0;
	double bcs = 0.0;
	printf("\t\t\t Hello\nThis program will help you calculate your BCS score\n\n");

	harris = getHarris();
	
	coaches = getCoaches();

	computerRank = getComputer();
	
	bcs = (harris + coaches + computerRank) / 3;
	
	printf("Your teams BCS score is: %.2lf\n", bcs);
	return 0;
}

double getHarris ()
{
	double harris = 0.0;
	
	printf("Please enter your teams Harris Poll score:\n");
	scanf("%lf", &harris);

	harris = harris / 2850;
	return harris;

}

double getCoaches ()
{
	double coaches = 0.0;
	
	printf("Please enter your teams Coaches Poll score:\n");
	scanf("%lf", &coaches);

	coaches = coaches / 1475;
	return coaches;

}

double getComputer ()
{
	double computer = 0.0;
	
	printf("Please enter your teams Computer Ranking score:\n");
	scanf("%lf", &computer);

	return computer;

}
