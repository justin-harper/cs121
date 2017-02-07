#include <stdio.h>
#include <math.h>


int maleOrFemale(void);

double getHeight(void);

double getWeight(void);

double getAge(void);

double calculateBMR (int gender, double weight, double hInches, double age);

int getLifestyle (void);

double calculateCalories (double BMR, int lifestyle);

int part1 (void);

int part2(void);

int calcBonus(int question, char TF);

int part3(void);

int readInt(FILE * infile);

int printStuff2(void);

double calcAverage (int num1, int num2, int num3, int num4, int num5);

int calHiVal (int num1, int num2, int num3, int num4, int num5);

int calLowVal (int num1, int num2, int num3, int num4, int num5);
