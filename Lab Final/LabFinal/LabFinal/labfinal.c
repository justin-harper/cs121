#include "labfinal.h"



FILE *openfileIn ()
{
	FILE * inFile = NULL;
	char tryagain = '\0';

	printf("Opening file: \"plaintext.txt\"\n");
	do
	{
		inFile = fopen("plaintext.txt", "r");
		if (inFile == NULL)
		{
			printf("error! would you like to try again? (y or n)\n");
			scanf(" %c", &tryagain);

			if (tryagain == 'y')
			{
				continue;
			}
			else
			{
				break;
			}

		}
	}
	while (inFile == NULL);


	printf("success!\n");
	
	return inFile;
}

FILE *openfileOut (void)
{
	FILE *outFile = NULL;
	char tryagain = '\0';

	printf("Opening file: \"ciphertext.txt\"\n");
	do
	{
		outFile = fopen("ciphertext.txt", "w");
		if (outFile == NULL)
		{
			printf("error! would you like to try again? (y or n)\n");
			scanf(" %c", &tryagain);

			if (tryagain == 'y')
			{
				continue;
			}
			else
			{
				break;
			}

		}
	}
	while (outFile == NULL);

	printf("success!\n");

	return outFile;

}

void menu (void)
{
	int choice = 0;

	system("cls");
	
	printf("Please choose from the following:\n");
	printf("1. Encrypt\n");
	printf("2. Decrypt\n");
	printf("3. Exit\n");

	scanf("%d", &choice);

	switch (choice)
	{
	case 1: encrypt();
		break;
	case 2: decrypt();
		break;
	case 3: break;
	
	default:menu();
		break;
	}


	


	return;
}

void encrypt (void)
{
	FILE *inFile = NULL;
	FILE *outFile = NULL;

	
	int i = 0, length = 0;
	int shift = 0;
	char readIn [MAXLENGTH];
	char reading = '\0';

	inFile = openfileIn();
	outFile = openfileOut();

	system("pause");
	system("cls");



	while (!feof(inFile))
	{
		fscanf(inFile, "%c", &reading);
		if (reading != ' ' && reading != '\n')
		{
			readIn [i] = reading;
			
			i++;
			length++;
		}
		
		
			
	}
	
	

	i=0;

	while (i < length)
	{
		if (readIn[i] >= 'a' && readIn[i] <= 'z') //convert to upper
		{
			readIn[i] = readIn[i] - 'a' + 'A';
		}
		printf("%c", readIn[i]);
		i++;
	}


	printf("\n");
	system("pause");
	system("cls");

	do
	{
		printf("please enter the shift key:\n");
		scanf(" %d", &shift); 

	}
	while(shift < -25 || shift > 25);

	printf("You elected to shift by: %d\n", shift);

	system("pause");
	system("cls");

	

	shiftChar(readIn, length, shift);

	printf("your encrypted text is:\n\n");

	i = 0;

	while(i < length)
	{
		printf("%c", readIn[i]);
		fprintf(outFile, "%c", readIn[i]);
		i++;
	}

	printf("\n");

	printf("You encrypted %d charictors\n", i-1);




	return;
}

void shiftChar(char *readIn, int length, int shiftBy)
{
	int shift = 0, i = 0, tempShift = 0;

	shift = shiftBy;
	
	


	for(i=0; i < length; i++)
	{
		tempShift = 0;
		if ((readIn[i] - shift) < 'A')
		{
			tempShift = shift - (readIn[i] -  'A');
			readIn[i] = 'Z' - (tempShift -1);
		}
		else if (readIn[i] + shift > 'Z')
		{
			tempShift = shift - ('Z' - readIn[i]);
			readIn[i] = 'A' + (tempShift - 1);
		}
		else
		{
			readIn[i] = readIn[i] + shift;
		}





	}




	return;
}

void decrypt ()
{
	FILE *cypher = NULL;
	FILE *decrypt = NULL; 

	char readIn [MAXLENGTH];
	char reading = '\0';

	int i = 0, length = 0, shift = 0;

	cypher = fopen("ciphertext.txt", "r");
	if(cypher == NULL)
	{
		printf("error\n");
		return;
	}
	decrypt = fopen("decrypt.txt", "w");
	if(decrypt == NULL)
	{
		printf("error 2\n");
	}


	while (!feof(cypher))
	{
		fscanf(cypher, "%c", &reading);
		if (reading != ' ' && reading != '\n')
		{
			readIn [i] = reading;
			printf("%c", readIn[i]);
			i++;
			length++;
		}
		
		
			
	}

	do
	{
		printf("please enter the shift key:\n");
		scanf(" %d", &shift); 

	}
	while(shift < -25 || shift > 25);

	printf("You elected to shift by: %d\n", shift);

	
	system("pause");
	system("cls");

	shiftChar(readIn, length, (-1 * shift));

	printf("your decrypted text is:\n\n");

	i = 0;

	while(i < length)
	{
		printf("%c", readIn[i]);
		fprintf(decrypt, "%c", readIn[i]);
		i++;
	}

	printf("\n");
	printf("You decrypted %d charictors\n", i-1);

}




//ciphertext.txt