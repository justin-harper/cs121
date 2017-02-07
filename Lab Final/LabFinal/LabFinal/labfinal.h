#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define MAXLENGTH 2000

void starthere(void);

void menu (void);

FILE * openfileIn (void);

FILE *openfileOut (void);

void encrypt (void);

void decrypt (void);

void shiftChar(char *readIn, int length, int shiftBy);