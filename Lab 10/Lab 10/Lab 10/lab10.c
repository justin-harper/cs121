#include "lab10.h"


int part1(void)
{
	char a1 [] = {"the"}, a2 [] = {"a"}, a3 [] = {"one"}, a4 [] = {"some"}, a5 [] = {"any"};	
	char *article [] = {a1, a2, a3, a4, a5};
	
	char n1 [] = {"boy"}, n2 [] = {"girl"}, n3 [] = {"dog"}, n4 [] = {"town"}, n5 [] = {"car"};
	char *noun [] = {n1, n2, n3, n4, n5};
	
	char v1 [] = {"drove"}, v2 [] = {"jumped"}, v3 [] = {"ran"}, v4 [] = {"walked"}, v5 [] = {"skipped"};
	char *verb [] = {v1, v2, v3, v4, v5};
	
	char p1 [] = {"to"}, p2 [] = {"from"}, p3 [] = {"over"}, p4 [] = {"under"}, p5 [] = {"on"};
	char *prep [] = {p1, p2, p3, p4, p5};

	int word [6];

	int i = 0;
	
	

	// article, noun, verb, preposition, article, and noun
	for (i = 0; i < 20; i++)
	{
	
		genRand(word);
		printf("%s %s %s %s %s %s\n\n", article[word[0]], noun[word[1]], verb[word[2]], prep[word[3]], article[word[4]], noun[word[5]]);

	}
	
}

void genRand (int word[])
{
	int i =0;
	for(i=0; i<6;i++)
	{
		rand(); rand(); rand();
		
		word[i] = rand() % LENGTH;
	}

	return;
}