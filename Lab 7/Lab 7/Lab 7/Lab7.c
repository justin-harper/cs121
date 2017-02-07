#include "Lab7.h"

int part1(void)
{
	int month = 0;
	int year = 0;
	double price = 0.0;
	double pricePerHour = 0.0;


	int customerNumber = 0;
	int hours = 0;

	
	FILE *input = NULL;
	FILE *output = NULL;
	output = fopen("output.txt", "w");
	input = fopen("input.txt", "r");
	if(input == NULL || output == NULL)
	{
		return 0;
	}
	
	

	fscanf(input, "%d %d", &month, &year);

	printf("month: %d, year: %d\n", month , year);

	while(!feof(input))
	{
	
	fscanf(input, "%d %d", &customerNumber, &hours);
	
	calcPrice(hours, &price, &pricePerHour);
	printf("customer #: %d, hours %d, price: %.2lf, price per hour: %.2lf\n", customerNumber, hours, price, pricePerHour);
	fprintf(output, "customer #: %d, hours %d, price: %.2lf, price per hour: %.2lf\n", customerNumber, hours, price, pricePerHour);
	}
	/*do
	{


	}
	while();*/


	return 0;
}

void calcPrice (int hours, double *price, double *costPerHour)
{
	double price2 = 0.0;
	double initialPrice = 7.99;
	double hours2 = 0;

	hours2 = hours;
	if(hours <= 10)
	{
		price2 = initialPrice;
	}
	else
	{
		hours = hours -10;
		price2 = initialPrice + (1.99 * hours);
	}

	*price = price2;

	*costPerHour = price2/hours2;

	return;



}


int part2(void)
{
	int t = 0;
	double r = 0.0;

	FILE * output = NULL;

	output = fopen("output.txt", "w");

	if(output == NULL)
	{
		return 0;
	}

	printf("R(t) = 203.265 X (1.071)^t, please enter a value for t years since 1984:\n");
	scanf(" %d", &t);

	r = revenue(t);

	printf("revenue: %.2lf million\n", r);

	
	//t = predict(200, output);
	//t = 1984 + t - 1;

	t = predict(1000000, output);

	t = 1984 + t - 1;

	printf("year: %d\n", t);

	return;


}

double revenue(int t)
{
	//R(t) = 203.265 X (1.071)^t
	double r = 0.0;

	r = 203.265 * pow(1.071, t);

	return r;
}


int predict (int revenue, FILE * output)
{
		//R(t) = 203.265 X (1.071)^t
	int t = 0;
	int t2 = 0;
	int rev = 0;
	double result = 0.0;

	rev = revenue;
	do
	{
		result = 203.265 *(pow(1.071, t));
		//printf("%lf, %d\n", result, t);
		t2 = 1984 + t;

		fprintf(output, "year: %d, revenue: %.2lf\n", t2, result);
		
		t++;

	}
	while( result <= rev);

	return t;
	





}
