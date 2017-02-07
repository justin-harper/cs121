#include "Lab6.h"

int part1(void)
{
	int sum = 0;
	int number = 0;
	int index = 0;
	int tof = 1;

	int dumby = 0;
	
	FILE * input = NULL;
	input = openFile();

	if(input == NULL)
	{
		printf("error");
		return 0;
	}

	while(!feof(input))
	{
		fscanf(input, "%d", &number);
		sum += number;

	}
	
	printf("sum: %d\n", sum);
		
		for (index = 2; (index <= sum) && (tof ==1); index++)
		{
				
			if(sum % index == 0 && index != sum)
			{
				tof = 0;
				printf("%d is not prime\n", sum);
			}

			if(index == sum)
			{
				{
					printf("%d is prime\n", sum);

				}
			}
		}
	

	sum = sumDigits(sum);
	printf("sum of digits: %d\n", sum);
	tof = 1;

		for (index = 2; (index <= sum) && (tof ==1); index++)
		{
				
			if(sum % index == 0 && index != sum)
			{
				tof = 0;
				printf("%d is not prime\n", sum);
			}

			if(index == sum)
			{
				{
					printf("%d is prime\n", sum);

				}
			}
		}

	

	






	return 1;
}

FILE * openFile(void)
{
	FILE * input = NULL;
	
	
		input = fopen("input.txt", "r");
	
	
	
	return input;

}

int sumDigits(int num)
{
	int sum = 0;
	while (num != 0)
	{
		sum = sum + num %10;
		num = num / 10;
	}

	return sum;
}


int part2(void)
{
	int number = 0;
	int fact = 0;

	printf("Please enter a number to factorial:\n");
	scanf(" %d", &number);


	fact = factorial(number);
	printf("%d factorial = %d\n", number, fact);


}

int factorial(int n)
{
	int index = 0;
	
	int fact = 0;
	if(n == 0)
	{
		fact = 1;
	}
	else if (n == 1)
	{
		fact = 1;
	}
	else
	{
		fact = n;
		for(index = 1; index < n; index++)
		{
			fact = fact * (n - index);

		}
	}
	


	return fact;
}

int part3(void)
{
	int number = 0;
	int term = 0;

	printf("Please enter a number to determine (fibinachi sequence):\n");
	scanf(" %d", &number);

	term = fib(number);

	printf("%d\n", term);


}

int fib(int term)
{
	int number = 0;
	int num1 = 0;
	int num2 = 1;
	int i = 0;

	for(i = 0; i< 
		term; i++)
	{
		if (term <= 1)
		{
			number = 0;
			term = i;
		}
		else
		{
			term = num1 + num2;
			num1 = num2;
			num2 = term;
		}



	}
	return term;





/*
	if(term == 1)
	{
		number = 0;
	}
	else if(term == 2)
	{
		number = 1;
	}
	else
	{
		for(i = 0; i< term; i++)
		{
			

		}

	}
*/
	return number;
}