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



#include <stdio.h>
#include <math.h>
#define PI 3.14159 


//Function prototypes:
int startHere ();
double newtonII (double mass, double acceleration);
int newton ();
double volumeCylinder (double radius, double height);
int volume();
int encodeChar ();
double distance2Pts (double x1, double y1, double x2, double y2);
int distance ();
double myTangent (double theta);
int tan1 ();
double equivilentParallelResistance (double R1, double R2, double R3);
int resistance ();
double generalEqn (double x,double y, double z, int a);
int genEqn ();
int jurassicParkFTW();