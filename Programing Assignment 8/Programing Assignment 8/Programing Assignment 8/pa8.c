#include "pa8.h"


void startHere(void)
{

	char dest [SIZE] = {'\0'};
	char source [SIZE] = {'a','b','c','d','e','\0'};



	stringCopy(source, dest, SIZE);

	printf("%s\n", dest);

	return;
}


void stringCopy(char *source, char *dest, int maxLength)
{
	int i = 0;

	while (i < maxLength && source[i] != '\0')
	{
		dest[i] = source [i];
		i++;
	}

	return;
}

void part2(void)
{
	int source [] = {1,6,3,7,5,2};
	int size = 0, target = 0, indexOfTarget = -1;
	
	size =  sizeof(source)/ sizeof(int);

	target = 3;
	
	printArray(source, size);

	
	bubbleSort(source, size);
	printf("sorted!\n");
	printArray(source, size);

	binarySearch(source, size, target, &indexOfTarget);

	


	return;
}

void bubbleSort (int source [], int size)
{
	int i = 0, j = 0, temp1 = 0;
	
	for(i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if(source[j] > source [j+1])
			{
				temp1 = source[j];
				source[j] = source [j+1];
				source[j+1] = temp1;
			}
		}

	}


	return;
}

void printArray (int source [], int size)
{
	int i =0;

	printf("List:\n");

	for(i = 0; i < size; i++)
	{
		printf("%d\n", source[i]);
	}

	return;
}

void binarySearch (int source [], int size, int target, int *foundIndex)
{
	int LI = 0, RI = 0, MI = 0;

	*foundIndex = -1;

	RI = size - 1;

	while ((*foundIndex == -1) && (LI <= RI))
	{
		MI = (LI + RI) / 2;
		
		if(source[MI] == target)
		{
			*foundIndex = MI;
			printf("found %d at index %d\n", target, MI);
		}
		else if(source[MI] > target)
		{
			RI = MI -1;
		}
		else
		{
			LI = MI + 1;
		}

	}

	if(*foundIndex == -1)
	{
		printf("couldn't find it\n");
	}
	return;
}

void part4 (void)
{
	char string [SIZE] = "Madam Im Adam", dest [SIZE];
	
	
	removeSpace(string, (sizeof(string)/ sizeof(char)), dest);


	if(palindrome (dest, 0 , (sizeof(dest) / sizeof(char))) == 1)
	{
		printf("%s: is a palendrome\n", dest);
	}
	else
	{
		printf("%s: is not a palendrome\n", dest);
	}


	

	return;
}


int palindrome (char a [], int left, int right)
{
	int x = 0;
	
	if(left >= right)
	{
		if(a[left] == a[right])
		{
			x = 1;
		}
	}
	else
	{
		x = palindrome(a, left + 1, right - 1);
	}
	return x;
}

void removeSpace (char source [], int length, char *dest)
{
	//char dest [SIZE];
	int i = 0, j = 0;

	while( source[i] != '\0')
	{
		if(source [i] != ' ')
		{
			dest [j] = source [i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';


	return;
}


void part5(void)
{
	unsigned int x = 100;
	int sum = 0;
	
	sum = sumPrimes(x);

	printf("sum: %d\n", sum);
	
	return;
}

int sumPrimes (unsigned int x)
{
	if(x == 0)
	{
		return x;
	}
	else if(isPrime(x, x))
	{
		return x + sumPrimes( x-1);
	}


}

int isPrime( unsigned int x , int i)
{
	if(x % i == 0 && x != 2 && x != i)
	{
		return 0;
	}
	else
	{
		if (i < sqrt(x))
		{
			return (isPrime( x, i+1));

		}
		else 
		{
				return 1;
		}
	}

}



