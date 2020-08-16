#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

struct node* add_at_begin(struct node *head,int data) {
	struct node *temp = malloc(sizeof(struct node));

	temp->data = data;
	temp->link = head;

	return temp;
}

void print_data(struct node *head){

	if (head == NULL)
	{
		printf("Linked list is empty\n");
	}

	struct node *ptr = NULL;
	ptr = head;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

int main() {
	struct node *head = malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;

	struct node *current = malloc(sizeof(struct node));
	current->data = 98;
	current->link = NULL;
	head->link = current;

	head = add_at_begin(head,67); // here we need to return the head because it is pass by value
	print_data(head);

	head = add_at_begin(head,85);
	print_data(head);

	return 0;
}