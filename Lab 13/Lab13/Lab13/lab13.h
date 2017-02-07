#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node
{
	int data;
	struct node *next;
}Node;



void part1(void);

Node *newNode (int data);

void insertInOrder(Node **list, int data);

void printList (Node *list);