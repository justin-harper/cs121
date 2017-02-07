#include <stdio.h>


//Prototypes
FILE * input_file (void);

FILE * output_stats (void);

FILE * output_ascii (void);

int startHere();

char read_character (FILE * infile);

int determine_ascii_value(char character);

int is_line(char character);

int is_vowel (char character);

int is_digit (char character);

int is_alpha (char character);

int is_lower(char character);

int is_upper (char character);

int is_alnum (char character);

int is_punct (char character);

void print_int(FILE * outfile, int number);

void print_stats(FILE * outfile, char header[], int number);