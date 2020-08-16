#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

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

void add_at_begin(struct node* *head,int data) {
	struct node* ptr = malloc(sizeof(struct node));
	ptr->data = data;
	ptr->link = *head;

	*head = ptr;
}

int main(){
	struct node *head = malloc(sizeof(struct node));
	head->data = 65;
	head->link = NULL;

	struct node *ptr = malloc(sizeof(struct node));
	ptr->data = 98;
	ptr->link = NULL;
	head->link = ptr;

	add_at_begin(&head,87); // here we don't need to return the head value because it is pass by reference
	print_data(head);

	add_at_begin(&head,48);
	print_data(head);

	return 0;
}