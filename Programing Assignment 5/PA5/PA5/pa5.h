/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 5, version 0.1												 *
*																						 *
*		NOTE: this is part 1															 *
*																						 *
*	Description:																		 *
*	This program reads values from a file and											 *
*	answers to the following questions:													 *
*																						 *
*		Is the value a multiple of 7, 11, or 13?										 *
*		Is the sum of the digits odd or even?											 *
*		Is the value a prime number?													 *
*																						 *
******************************************************************************************

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void computations (FILE * file);

FILE * openFileWrite(void);

FILE * openFileRead(void);

void fillFile (FILE * file);

void readInt (FILE * file, int *value);

int sumDigits(int num);

void isPrime(int value);