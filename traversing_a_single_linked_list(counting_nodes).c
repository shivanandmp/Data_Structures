#include <stdio.h>
#include <stdlib.h>

// traversing a single linked list means visiting every node of the list until the end node is reached

struct node
{
	int data;
	struct node *link;
};

void count_of_nodes(struct node *head){
	int count = 0;
	if(head == NULL) {
		printf("Linked list is empty\n");
	}

	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
		++count;
		ptr = ptr->link;
	}
	printf("Count: %d\n", count);
}

int main(){
	struct node *head = malloc(sizeof(struct node)); // here we haven't typecasted but it is always a good practice to typecast
	head->data = 45;
	head->link = NULL;

	struct node *current = malloc(sizeof(struct node));
	current->data = 98;
	current->link = NULL;
	head->link = current;

	current = malloc(sizeof(struct node));
	current->data = 3;
	current->link= NULL;
	head->link->link = current;

	count_of_nodes(head);

	return 0;
}