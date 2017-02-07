#include <stdio.h>
#include <math.h>
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

//function prototypes:

double read_double (FILE * infile);

int read_integer (FILE * infile);

double calculate_sum (double number1, double number2, double number3, double number4, double number5);

double calculate_mean (double sum, int number);

double calculate_deviation (double number, double mean);

double calculate_variance (double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

double calculate_variance_array (double deviation [], int number);

double calculate_standard_deviation (double variance);

double find_max (double number1, double number2, double number3, double number4, double number5);

double find_min (double number1, double number2, double number3, double number4, double number5);

void print_double (FILE *outfile, double number);

void print_gpa_mean (FILE *outfile, double number);

void print_class_standing_mean (FILE *outfile, double number);

void print_age_mean (FILE *outfile, double number);

void printLine (FILE *outfile);

void print_gpa_sd (FILE *outfile, double number);

void print_gpa_min (FILE *outfile, double number);

void print_gpa_max (FILE *outfile, double number);

void printSmiley(void);

void startHere();