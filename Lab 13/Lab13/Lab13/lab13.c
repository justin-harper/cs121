#include "lab13.h"

void part1(void) //Write a function insert_in_order () that will dynamically place a node in the correct position in ascending order
{
	Node *list = NULL;
	

	insertInOrder(&list, 3);
	insertInOrder(&list, 2);
	insertInOrder(&list, 50);

	printList(list);

	return;
}


void insertInOrder(Node **list, int data)
{
	Node *current = NULL, *previous = NULL, *aNewNode = NULL;
	
	aNewNode = newNode(data);

	if(*list == NULL)//empty list
	{
		*list = aNewNode;
	}
	else // the list is not empty
	{
		current = *list;

		while(current != NULL && current -> data < data)
		{
			previous = current;
			current = current ->next;
		}
		//current is null or current.next > data

		if (previous != NULL) 
		{
			previous -> next = aNewNode;
			aNewNode ->next = current;
		}
		else//previous = null
		{			
			aNewNode -> next = *list;
			*list = aNewNode;
		}		
	}
}

Node * newNode (int data)
{
	Node *newData = (Node *) malloc(sizeof(Node));

	newData -> data = data;
	newData -> next = NULL;

	return newData;
}

void printList (Node *list)
{
	if(list != NULL)
	{
		printf("%d -> ", list -> data);
		printList(list -> next);
	}
	else
	{
		printf("NULL\n");
	}

	return;
}