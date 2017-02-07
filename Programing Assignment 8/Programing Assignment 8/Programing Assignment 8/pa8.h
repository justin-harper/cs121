#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define SIZE 100



void startHere(void);

void stringCopy(char *source, char *dest, int maxLength);

void part2(void);

void bubbleSort (int source [], int size);

void printArray (int source [], int size);

void binarySearch (int source [], int size, int target, int *foundIndex);

void removeSpace (char source [], int length, char *dest);

int palindrome (char a [], int left, int right);

void part5(void);