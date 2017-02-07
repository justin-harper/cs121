#include "functions.h"

FILE * input_file(void)
{
	FILE * input_file = NULL;

	input_file = fopen("input.dat","r");
	return input_file;
}

FILE * output_stats (void)
{
	FILE * output_file = NULL;
	output_file = fopen("output_stats.dat", "w");
	return output_file;
}

FILE * output_ascii (void)
{
	FILE * output_file = NULL;
	output_file = fopen("output_ascii.dat", "w");
	return output_file;
}



char read_character (FILE * infile)
{
	char character = '/0';

	fscanf(infile,"%c",&character);
		
	return character;
}

int determine_ascii_value(char character)
{
	int ascii = character;
	return ascii;
}

int is_line(char character)
{
	if(character == 10)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int is_vowel (char character)
{
	if(((character >= 65) && (character <= 90) || ((character >= 97) && (character <= 122))))
	{
		if(
				(character == 65) ||
				(character == 69) ||
				(character == 73) ||
				(character == 79) ||
				(character == 85) ||
				(character == 89) ||
				(character == 97) ||
				(character == 101)||
				(character == 105)||
				(character == 111)||
				(character == 117)||
				(character == 121)
			)
			{
				return 2;
			}
		else
		{
			return 0;
		}
	}
	
	else
	{
		return 0;
	}
}

int is_digit (char character)
{
	if((character >= 48) && (character<= 57))
	{
		return 3;
	}
	else
	{
		return 0;
	}
}

int is_alpha (char character)
{
	if(((character >= 65) && (character <= 90) || ((character >= 97) && (character <= 122))))
	{
		return 4;
	}
	else
	{
		return 0;
	}
}

int is_lower(char character)
{
	char a = character; 
	
	if((a >= 97) && (a <= 122))
	{
		return 5;
	}
	else 
	{
		return 0;
	}

}

int is_upper (char character)
{
	if((character >= 65) && (character <= 90))
	{
		return 6;
	}
	else
	{
		return 0;
	}
}

int is_space (char character)
{
	if (character == 32)
	{
		return 7;
	}
	else
	{
		return 0;
	}
}

int is_alnum (char character)
{
	int a = is_alpha(character);
	int b = is_digit(character);

	if((a == 1) || (b == 1))
	{
		return 8;
	}
	else
	{
		return 0;
	}
}

int is_punct (char character)
{
	if(
				(character == 33) ||
				(character == 34) ||
				(character == 44) ||
				(character == 46) ||
				(character == 58) ||
				(character == 59) ||
				(character == 63)
	  )
	{
		return 9;
	}
	else
	{
		return 0;
	}
				
}

void print_int(FILE * outfile, int number)
{
	if(outfile == NULL)
	{
		printf("error");
		return;
	}

	fprintf(outfile,"%d %c\n", number, number);
	return;
}

void print_stats(FILE * outfile, char header[], int number)
{
	if(outfile == NULL)
	{
		printf("error");
		return;
	}
	
	fprintf(outfile, "%s %d\n", header, number);
	return;
}

int startHere()
{
	FILE * input = input_file();
	FILE * output_st = output_stats();
	FILE * output_as = output_ascii();
	int i = 0;
	int lines = 0;
	int num_vowles = 0;
	int digits = 0;
	int alphas = 0;
	int lowers = 0;
	int uppers = 0;
	int spaces = 0;
	int alnums = 0;
	int pncts = 0;
	
	char out = '/0';
	int b = 0;

	if (input == NULL)
	{
		printf("error file not opened");
		return 0;
	}
	
	for(i=0;i<9;i++)
	{
		
		out = read_character(input);
		print_int(output_as,out);
		if(is_vowel(out) == 2)
		{
			num_vowles++;
		}
		if(is_line(out) == 1)
		{
			lines++;
		}
		if(is_digit(out) == 3)
		{
			digits++;
		}
		if(is_alpha(out) == 4)
		{
			alphas++;
		}
		if(is_lower(out) == 5)
		{
			lowers++;
		}
		if(is_upper(out) == 6)
		{
			uppers++;
		}
		if(is_space(out) == 7)
		{
			spaces++;
		}
		if(is_alnum(out) == 8)
		{
			alnums++;
		}
		if(is_punct(out)==9)
		{
			pncts++;
		}

	}
	
	print_stats(output_st,"Number Lines:  ", lines);
	print_stats(output_st,"Number Vowles: ", num_vowles);
	print_stats(output_st,"Number Digits: ", digits);
	print_stats(output_st,"Number Alphas: ", alphas);
	print_stats(output_st,"Number Lowers: ", lowers);
	print_stats(output_st,"Number Uppers: ", uppers);
	print_stats(output_st,"Number Spaces: ", spaces);
	print_stats(output_st,"Number Alnums: ", alnums);
	print_stats(output_st,"Number Punct.: ", pncts);
	/*a = read_character(input);
	
	printf("%c", a);
	printf("\n");
	b = determine_ascii_value(a);
	printf("%d",b);
	b = is_line(a);
	printf("\n");
	printf("%d", b);
	printf("\n");*/

}