#include<stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void add_at_end(struct node* *ptr, int data) { // this function adds without traversing the whole list , so it is faster than the previous one
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	(*ptr)->link = temp;
	*ptr = temp;
}

void print_data(struct node *head) {
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

void delete_at_pos(struct node* head,int pos) {
	struct node* ptr = head;
	pos--;
	while(pos != 1) {
		ptr = ptr->link;
		pos--;
	}
	struct node *temp = ptr->link;
	ptr->link = temp->link;
	temp->link = NULL;
	free(temp);
	temp = NULL;
}

int main() {
	struct node *head = malloc(sizeof(struct node));
	head->data = 65;
	head->link = NULL;
	struct node *ptr = head;

	add_at_end(&ptr,66);
	add_at_end(&ptr,67);
	add_at_end(&ptr,68);
	add_at_end(&ptr,69);
	print_data(head);

	delete_at_pos(head,3);
	print_data(head);

	add_at_end(&ptr,70);
	print_data(head);

	delete_at_pos(head,5);
	print_data(head);

	return 0;
}