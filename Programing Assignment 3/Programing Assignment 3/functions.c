#include "functions.h"
#define NUMBERSTUDENTS 5 //note this sets the number of students in the data file
						 //also note this program only works when NUMBERSTUDENTS = 5
/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 3, version 1.0												 *
*																						 *
*	Description:																		 *
*	This program will  processes numbers, corresponding to student records				 *
*	read in from a file, and writes the required results to an output file				 *
*	This program has some input validation and divide by 0								 *
*	validation, still be sure input is clean!											 *
*																						 *
******************************************************************************************

*/

//Reads one double precision number from the input file. Note: You may assume that the file only contains real numbers.
double read_double (FILE * infile)
{
	double read = 0.0;
	fscanf(infile, " %lf", &read);
	return read;
}

//Reads one integer number from the input file.
int read_integer (FILE * infile)
{
	int read = 0;
	fscanf(infile, "%d", &read);
	return read;
}

//Finds the sum of number1, number2, number3, number4, and number5 and returns the result.
double calculate_sum (double number1, double number2, double number3, double number4, double number5)
{
	return (number1 + number2 + number3 + number4 + number5);
}

// Determines the mean through the calculation sum / number and returns the result. You need to check to make sure that number is not 0.
//If it is 0 the function returns -1.0 (we will assume that we are calculating the mean of positive numbers), otherwise it returns the mean.
double calculate_mean (double sum, int number)
{
	if(number == 0)
	{
		printf("error divde by 0");
		return -1.0;
	}
	else
	{
		return (sum / number);
	}
}

//Determines the deviation of number from the mean and returns the result. The deviation may be calculated as number - mean.
double calculate_deviation (double number, double mean)
{
	return (number - mean);
}

//Determines the variance through the calculation: ((deviation1)^2 + (deviation2)^2 + (deviation3)^2 + (deviation4)^2 + (deviation5)^2) / number 
//and returns the result. Hint: you may call your calculate_mean ( ) function to determine the result!
double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	return calculate_mean(calculate_sum(pow(deviation1,2), pow(deviation2,2), pow(deviation3,2), pow(deviation4,2), pow(deviation5,2)), number);
}

double calculate_variance_array (double deviation [], int number)
{
	return calculate_mean(calculate_sum(pow(deviation[0],2), pow(deviation[1],2), pow(deviation[2],2), pow(deviation[3],2), pow(deviation[4],2)), number);
}

//Calculates the standard deviation as sqrt (variance) and returns the result. Recall that you may use the sqrt ( ) function that is found in math.h.
double calculate_standard_deviation (double variance)
{
	return sqrt(variance);
}

//Determines the maximum number out of the five input parameters passed into the function, returning the max.
double find_max (double number1, double number2, double number3, double number4, double number5)
{
	double max = number1;
	
	if(number2 > max)
	{
		max = number2;
	}
	if(number3 > max)
	{
		max = number3;
	}
	if(number4 > max)
	{
		max = number4;
	}
	if(number5 > max)
	{
		max = number5;
	}

	return max;
}

// Determines the minimum number out of the five input parameters passed into the function, returning the min.
double find_min (double number1, double number2, double number3, double number4, double number5) 
{
	double min = number1;
	
	if(number2 < min)
	{
		min = number2;
	}
	if(number3 < min)
	{
		min = number3;
	}
	if(number4 < min)
	{
		min = number4;
	}
	if(number5 < min)
	{
		min = number5;
	}

	return min;
}

// Prints a double precision number (to the hundredths place) to an output file.
void print_double (FILE *outfile, double number) 
{
	fprintf(outfile, "%.2lf\n", number);
	
	return;
}

void print_gpa_mean (FILE *outfile, double number) 
{
	fprintf(outfile, "\t %.2lf\t -- GPA Mean\n", number);
	
	return;
}

void print_class_standing_mean (FILE *outfile, double number) 
{
	fprintf(outfile, "\t %.2lf\t -- Class Standing Mean\n", number);
	
	return;
}

void print_age_mean (FILE *outfile, double number) 
{
	fprintf(outfile, "\t %.2lf\t -- Age Mean\n", number);
	
	return;
}

void printLine (FILE *outfile) 
{
	fprintf(outfile, "\n");
	
	return;
}

void print_gpa_sd (FILE *outfile, double number) 
{
	fprintf(outfile, "\t %.2lf\t -- GPA Standard Deviation\n", number);
	
	return;
}

void print_gpa_min (FILE *outfile, double number) 
{
	fprintf(outfile, "\t %.2lf\t -- GPA Min\n", number);
	
	return;
}

void print_gpa_max (FILE *outfile, double number) 
{
	fprintf(outfile, "\t %.2lf\t -- GPA Max\n", number);
	
	return;
}

void printSmiley(void) //gotta have an easter egg!
{
	printf("\n\n\n");   
	
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

	return;
}

/*startHere() does the following:
Opens an input file "input.dat" for reading;
Opens an output file "output.dat" for writing;
 
Reads five records from the input file (input.dat); You will need to use a combination of read_double ( ) and read_integer ( ) function calls here!
 
Calculates the sum of the GPAs;
Calculates the sum of the class standings;
Calculates the sum of the ages;
 
Calculates the mean of the GPAs, writing the result to the output file (output.dat);
Calculates the mean of the class standings, writing the result to the output file (output.dat);
Calculates the mean of the ages, writing the result to the output file (output.dat);
 
Calculates the deviation of each GPA from the mean (Hint: need to call calculate_deviation ( ) 5 times)
Calculates the variance of the GPAs
Calculates the standard deviation of the GPAs, writing the result to the output file (output.dat);
 
Determines the min of the GPAs, writing the result to the output file (output.dat);
Determines the max of the GPAs, writing the result to the output file (output.dat);
 
Closes the input and output files (i.e. input.dat and output.dat)

*/

void startHere()
{
	//variables:
	
	//files:
	FILE * input = NULL;
	FILE * output = NULL;
	
	//student ID
	int sid [NUMBERSTUDENTS];
	/*
	int sid1 = 0; 
	int sid2 = 0;
	int sid3 = 0;
	int sid4 = 0;
	int sid5 = 0;
	*/

	//GPA
	double gpa [NUMBERSTUDENTS];
	/*
	double gpa1 = 0.0;
	double gpa2 = 0.0;
	double gpa3 = 0.0;
	double gpa4 = 0.0;
	double gpa5 = 0.0;
	*/
	
	double minGPA = 0.0;
	double maxGPA = 0.0;
	
	//class standing
	int st [NUMBERSTUDENTS];
	/*
	int st1 = 0;
	int st2 = 0;
	int st3 = 0;
	int st4 = 0;
	int st5 = 0;
	*/

	//age
	double age [NUMBERSTUDENTS];
	/*
	double age1 = 0.0;
	double age2 = 0.0;
	double age3 = 0.0;
	double age4 = 0.0;
	double age5 = 0.0;
	*/
	
	//totals
	double sumGPA = 0.0;
	double sumClassStanding = 0.0;
	double sumAge = 0.0;

	//means
	double meanGPA = 0.0;
	double meanClassStanding = 0.0;
	double meanAge = 0.0;

	double diviation [NUMBERSTUDENTS];
	/*double diviationS1 = 0.0;
	double diviationS2 = 0.0;
	double diviationS3 = 0.0;
	double diviationS4 = 0.0;
	double diviationS5 = 0.0;*/

	double variance = 0.0;
	double gpaStandardDiviation = 0.0;
	

	input = fopen("input.dat","r");
	output = fopen("output.dat","w");
	if(input == NULL)
	{
		printf("error input");
		return;
	}
	if(output == NULL)
	{
		printf("error output");
		return;
	}
	
	//student 1
	sid[0] = read_integer(input);
	gpa[0] = read_double(input);
	st[0] = read_integer(input);
	age[0] = read_double(input);
	 

	//student 2
	sid[1] = read_integer(input);
	gpa[1] = read_double(input);
	st[1] = read_integer(input);
	age[1] = read_double(input);

	//student 3
	sid[2] = read_integer(input);
	gpa[2] = read_double(input);
	st[2] = read_integer(input);
	age[2] = read_double(input);

	//student 4
	sid[3] = read_integer(input);
	gpa[3] = read_double(input);
	st[3] = read_integer(input);
	age[3] = read_double(input);

	//student 5
	sid[4] = read_integer(input);
	gpa[4] = read_double(input);
	st[4] = read_integer(input);
	age[4] = read_double(input);

	sumGPA = calculate_sum(gpa[0], gpa[1], gpa[2], gpa[3], gpa[4]);
	sumClassStanding = (int)calculate_sum(st[0], st[1], st[2], st[3], st[4]);
	sumAge = calculate_sum(age[0], age[1], age[2], age[3], age[4]);

	meanGPA = calculate_mean(sumGPA, NUMBERSTUDENTS);
	meanClassStanding = calculate_mean(calculate_sum(st[0], st[1], st[2], st[3], st[4]), NUMBERSTUDENTS); // yes you can call functions inside other funtions...it evaluates from the inside out
	meanAge = calculate_mean(sumAge, NUMBERSTUDENTS);

	
	diviation[0] = calculate_deviation(gpa[0], meanGPA);
	diviation[1] = calculate_deviation(gpa[1], meanGPA);
	diviation[2] = calculate_deviation(gpa[2], meanGPA);
	diviation[3] = calculate_deviation(gpa[3], meanGPA);
	diviation[4] = calculate_deviation(gpa[4], meanGPA); 
	
	
	/*
	diviationS1 = calculate_deviation(gpa1, meanGPA);
	diviationS2 = calculate_deviation(gpa2, meanGPA);
	diviationS3 = calculate_deviation(gpa3, meanGPA);
	diviationS4 = calculate_deviation(gpa4, meanGPA);
	diviationS5 = calculate_deviation(gpa5, meanGPA);
	*/
	

	/*
	variance = calculate_variance(diviationS1, diviationS2, diviationS3, diviationS4, diviationS5, NUMBERSTUDENTS);
	*/

	variance = calculate_variance_array(diviation, NUMBERSTUDENTS);

	gpaStandardDiviation = calculate_standard_deviation(variance);

	minGPA = find_min(gpa[0], gpa[1], gpa[2], gpa[3], gpa[4]);
	maxGPA = find_max(gpa[0], gpa[1], gpa[2], gpa[3], gpa[4]);

	print_gpa_mean(output, meanGPA);
	print_class_standing_mean(output, meanClassStanding);
	print_age_mean(output, meanAge);

	printLine(output);

	print_gpa_sd(output, gpaStandardDiviation);
	print_gpa_min(output, minGPA);
	print_gpa_max(output, maxGPA);

	//fclose(input);
	//fclose(output);//_fcloseall() works just as well

	

	_fcloseall();

	printSmiley();
	return;
}

//all done YAY! ;)
