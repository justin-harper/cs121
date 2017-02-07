#include "lab5.h"






int part1()
{
	int i = 0;
	FILE * input = openFile();
	
	int read1 = 0;
	int read2 = 0;
	int read3 = 0;
	int read4 = 0;

	int sum = 0;
	int taxbracket = 0;

	fscanf(input, "%d", &read1);
	fscanf(input, "%d", &read2);
	fscanf(input, "%d", &read3);
	fscanf(input, "%d", &read4);

	

	sum = read1 + read2 + read3+ read4;

	taxbracket = determineTaxBracket(sum);

	switch (taxbracket)
	{
	case 1: printf("Low income\n");
		break;
	case 2: printf("Medium income\n");
		break;
	case 3: printf("High income\n");
		break;
	}

	fcloseall();

	return 1;



}

FILE * openFile()
{
	FILE * infile = NULL;
	do
	{
	infile = fopen("salaries.txt", "r");
	}

	while (infile == NULL);

	return infile;
}

int determineTaxBracket (int income)
{
	int taxbracket = 0;
	
	if(income < 15000)
	{
		taxbracket = 1;
	}
	else
	{
		if((income >= 15000) && (income <=200000))
		{
			taxbracket = 2;
		}
		else
		{
			taxbracket = 3;
		}

	}

	return taxbracket;

	
}

int part2()
{
	int i = 0;
	int index = 0;
	int sum = 0;
	double average = 0;

	char fileName [FILEnAMEsIZE];
	FILE * input = NULL;
	FILE * output = NULL;
	
	do
	{
	printf("Please Enter the name of the file to read from\n");
	scanf("%s", fileName);

	input = fopen(fileName, "r");
	}
	while(input == NULL);


	while(!feof(input))
	{
		fscanf(input, "%d", &i);
		sum += i;
		index++;
	}


	average = averageThings(sum, index);

	output = fopen("output.dat", "w");
	fprintf(output, "The average is: %.2lf\n", average);

	fcloseall();
	
	return 1;
}

double averageThings (int sum, int terms)
{

	return ((double)sum / terms);

}


int part3()
{
	FILE * input = NULL;
	FILE * output = NULL;

	int input1 = 0;
	int input2 = 0;
	int test = 0;
	int factor = 0;
	int intermidiate = 0;

	input = openFile2("part3input.txt", 1);
	output = openFile2("part3output.txt", 2);

	fscanf(input, "%d", &input1);
	fscanf(input, "%d", &input2);

	input1 = abs(input1);
	input2 = abs(input2);
	test = input1 % input2;
	factor = input2;
	while(test != 0)
	{
		intermidiate = test;
		test = factor % test;
		factor = intermidiate;


	}

	printf("GCD: %d\n", intermidiate);

	printf("%d\n",test);

	fprintf(output, "GCD: %d\n", intermidiate);

	fcloseall();





}

FILE * openFile2(char name [], int rw)
{
	FILE * filename = NULL;

	if(rw = 1)
	{

	filename = fopen(name, "r");

	}

	else
	{
		filename = fopen(name, "w");
	}

	return filename;
}

int part4()
{
	FILE * input = NULL;
	int high = 0;
	int low = TMP_MAX;
	int number = 0;

	input = openFile();
	
	
	
	while(!feof(input))
	{
		fscanf(input, "%d", &number);
		if(number >= high)
		{
			high = number;
		}

		if(number <= low)
		{
			low = number;
		}

	}

	printf("lowest: %d\n", low);
	printf("highest: %d\n", high);


	


	return 1;
}
