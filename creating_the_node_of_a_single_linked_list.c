#include <stdio.h>
#include <stdlib.h>

// a node is a combination of two different data types 
// we use structure to create a node

// a node is nothing but a self referential structure

struct node
{
	int data;
	struct node *link;
};

// a node of a single linked lists can have multiple datas but only one pointer

int main(){
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node)); // we can also avoid typecasting here in C Language

	head->data = 45; // we are accessing the data part of the first node and assigning it value 45 (head-> is nothing but *(head).)
	head->link = NULL; // assign it NULL to avoid wild pointer

	printf("%d\n", head->data);
	printf("%d\n", head->link);

	printf("%d\n", (*head).data); // using derefernce operator

	return 0;
}