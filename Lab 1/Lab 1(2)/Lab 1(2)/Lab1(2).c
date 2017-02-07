/*
Name: Justin Harper

Lab 1



*/



#include <stdio.h>


int main(void)
{

	//part2();
	//part3();
	//part4();
	//part5();
	part6();

	
	


}

int part2()
{
	int number1_int = 0;
	int number2_int = 0;
	double number1_float;
	double number2_float;



	printf("Please enter 2 integers seperated by a space\n");
	scanf("%d %d", &number1_int, &number2_int);

	printf("Please enter 2 decimal numbers seperated by a space\n");
	scanf("%lf %lf", &number1_float, &number2_float);

	printf("you entered A: %d\, B: %d\, C: %.2lf\, D: %.2lf\n", number1_int, number2_int, number1_float, number2_float);
	
	printf("the sum of A and B is: %d\n", number1_int + number2_int);

	printf("D-C = %.2lf\n", number2_float - number1_float);

	printf("A * C = %d\n", number1_int * (int)number1_float);

	printf("A / B using integer divison = %d\n", number1_int / number2_int);

	printf("A / B using decimal divison = %.2lf\n", number1_int / (double)number2_int);

	printf("A / D usint integer divison = %d\n", number1_int /(int)number2_float);

	printf("A / B using decimal divison = %.2lf\n", (double)number1_int / number2_int);

	printf("C %% D = %d\n", (int)number1_float % (int)number2_float);

	printf("A");
	evenOdd(number1_int);
	printf("B");
	evenOdd(number2_int);

	return 0;
}


int evenOdd (int a)
{
	if (a%2==0)
	{
		printf(" is even\n");
	}
	else
	{
		printf(" is odd\n");
	}
	return 0;
}


int part3()
{
	double voltage=0,current=0,resistance=0;
	
	printf("Ohm's Law states that Voltage = Current * Resistance\n");
	printf("Please enter the current (I) and the Resistance (R) of\nyour circut seperated by a space\n");

	scanf("%lf %lf", &current, & resistance);

	printf("The voltage of your circut it:\n%.2lf[V]\n", current * resistance);


	return 0;
}

int part4 ()
{
	//yes a loss of percision will ocurr, integer division will happen
	
	int voltage=0,power=0,resistance=0;
	
	printf("Joule's Law states that Power = (Voltage^2) / Resistance\n");
	
	printf("Please enter voltage and resistance seperated by a space\n");
	scanf("%d %d", &voltage, &resistance);

	power = voltage * voltage/resistance;
	
	printf("Power = %d\n", power);

	 


	return 0;
}

int part5()
{
	int x=0,a=0,b=0,c=0,d=0;
	double z = 1/4, y=0;
	
	printf("Our equation is: y = 3ax^3 +(1/4)bx^2 + 10cx + (-5)d\n(x, y, a, b, c, d are all integers)");
	
	printf("\nPlease enter the value for a\n");
	scanf("%d", &a);

	printf("\nPlease enter the value for b\n");
	scanf("%d", &b);

	printf("\nPlease enter the value for c\n");
	scanf("%d", &c);

	printf("\nPlease enter the value for d\n");
	scanf("%d", &d);

	printf("\nPlease enter the value for x\n");
	scanf("%d", &x);

	y = 3 * a * x * x * x + z * b * x *x + 10 * c* x + d * -5;

	printf("y = %.2lf", y);
	return 0;
}


int part6()
{
	double PI = 3.14159;
	double radius=0.0;
	double circumfrence = 0.0;
	printf("Circumfrence of a circle = 2 * PI * radius");
	printf("\nPlease enter the radius of the circle\n");
	scanf("%lf", &radius);

	circumfrence = 2 * PI * radius;
	printf("The circumfrence of the circle is:%.2lf\n", circumfrence); 
	
	return 0;
}

