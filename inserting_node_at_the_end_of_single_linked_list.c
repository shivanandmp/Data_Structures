#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void add_at_end(struct node *head, int data) {
	struct node *ptr, *temp;
	ptr = head;
	temp = malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	while(ptr->link != NULL){
		ptr = ptr->link;
	}

	ptr->link = temp;
	temp = NULL;
}

void print_data(struct node *head) {
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(){
	struct node *head = malloc(sizeof(struct node));
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

	add_at_end(head,67);
	print_data(head);
	
	add_at_end(head,68);
	print_data(head);
	
	return 0;
}