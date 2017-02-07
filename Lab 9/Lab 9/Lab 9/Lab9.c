#include "Lab9.h"

void part1(void)
{
	int length = 0;
	char string1[] = "CptS 121 is cool!";

	printString(string1);
	length = getLength(string1);

	printf("String Length: %d\n", length);
	printf("\n\n");
	reverse(string1, length);
	printf("\n\n");
	printString(string1);

}

void part2 (void)
{
	int x = 0;
	char string2 [] = "Life will ... Uh...Find a way";
	char string3 [SIZE] = {0};
	char string4 [] = "Z test";

	myStrCpy (string3, string2);

	printString(string3);

	myStrCat(string3, string2);

	printString(string3);

	x = myStrComp(string2, string4);

	printf("string compare: %d\n", x);

	printf("length: %d\n", getLength(string4));


}

void printString (char *string1)
{
	int i =0;char c;

	while (*(string1 + i) != '\0')
	{
		c = *(string1 + i);
		printf("%c", *(string1 + i));

		i++;
	}
	printf("\n");
	return;
	
}

int getLength (char *string1)
{
	int i =0;
	while (*(string1 + i) != '\0')
	{
		i++;
	}

	return i;
}

void reverse (char *string1, int length)
{
	char temp = '\0', t2 = '\0';
	int i = 0;
	int j = length - 1;

	for (i=0; i < length / 2 ; i++)
	{
		temp = *(string1 + i);
		t2 = *(string1 + j);
		*(string1 + i) = t2;
		*(string1 + j) = temp;
				
		j--;

	}
return;
}

void myStrCpy (char *string3, char *string2)
{
	int i = 0;
	int length = getLength(string2);

	for(i=0; i< length; i++)
	{
		*(string3 + i) = *(string2 + i);
	}
return;
}

void myStrCat (char * dest, char * source)
{
	char a = *dest;
	int i = 0;
	int j = 0;
	
	int length = getLength(source);

	while (*(dest + i) != '\0')
	{
		i++;
	}
	while(*(source + j) != '\0')
	{
		*(dest + i) = *(source + j);
		i++;
		j++;
	}
	
}

int myStrComp ( char * s1, char * s2)
{
	int tof = -2;
	int i = 0;
	char check1 = *s1;
	char check2 = *s2;
	int l1 = getLength(s1);
	int l2 = getLength(s2);

	while ( *(s1 + i) != '\0')
	{
		if (*(s1 + i) == *(s2 + i))
		{
			tof = 0;
		}
		else if( *(s1 + i) < *(s2 + i))
		{
			tof = -1;
			break;
		}
		else
		{
			tof = 1;
			break;
		}

		i++;
	}

	if (tof == -2)
	{
		printf("error\n");
	}

	return tof;
}

