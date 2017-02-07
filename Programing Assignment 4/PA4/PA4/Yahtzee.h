/*

******************************************************************************************
*	Name: Justin Harper																	 *
*	WSU ID: 10696738                                                                     *
*	Programing Assignment 4, version 0.1												 *
*																						 *
*	Description:																		 *
*	This program will let you play a game of Yahtzee									 *
*																						 *
******************************************************************************************

*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int startHere(void);

int menu1(void);

int printRules();

int playGame(void);

int rollDice ();

int sortDice(int * die1, int * die2, int * die3, int * die4, int * die5, int dice [5]);

int sumSameDice(int value, int dice []);

void threeOfAKind(int dice [], int * points);

int fullHouse (int values [], int * points);

int count (int dice [], int lookingFor);

int smallStright(int dice[], int * points);

int largeStright(int dice [], int * points);

int yahtzee (int dice [], int * points);

void chance (int dice [], int * points);

void endGame(int points);