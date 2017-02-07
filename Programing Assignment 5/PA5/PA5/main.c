/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 5, version 0.1												 *
*																						 *
*		NOTE: This is part 1															 *
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


#include "pa5.h"

int main(void)
{
	FILE * numbers = NULL;
	
	srand( ( unsigned int ) time( NULL ) );
	
	numbers = openFileWrite();

	fillFile( numbers );
	
	fclose( numbers );

	numbers = openFileRead();

	computations( numbers );

	return 0;
}