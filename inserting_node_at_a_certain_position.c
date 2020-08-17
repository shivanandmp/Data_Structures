#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void add_at_begin(struct node* *head,int data) {
	struct node* ptr = malloc(sizeof(struct node));
	ptr->data = data;
	ptr->link = *head;

	*head = ptr;
}

void add_at_pos(struct node* head, int data, int pos) {
	struct node *ptr1 = head;
	struct node *ptr2 = malloc(sizeof(struct node));
	ptr2->data = data;
	ptr2->link = NULL;

	pos--;
	while(pos != 1) {
		ptr1 = ptr1->link;
		pos--;
	}

	ptr2->link = ptr1->link;
	ptr1->link = ptr2;
}

struct node *add_at_end(struct node *ptr, int data) { // this function adds without traversing the whole list , so it is faster than the previous one
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	ptr->link = temp;
	return temp;
}

void print_data(struct node *head) {
    struct node *ptr = head;
    while(ptr != NULL) {
        printf("%d ",ptr->data);
        ptr = ptr->link;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = 45;
	head->link = NULL;

	struct node *ptr = head;

	ptr = add_at_end(ptr,98);
	ptr = add_at_end(ptr,3);
	ptr = add_at_end(ptr,36); // ptr is always storing the last node address

	print_data(head);

	ptr = add_at_end(ptr,76);
	ptr = add_at_end(ptr,57);
	print_data(head);

	add_at_pos(head,48,3);
	print_data(head);

	add_at_pos(head,89,7);
	print_data(head);

	add_at_pos(head,100,9);
	print_data(head);

	add_at_begin(&head,89);
	print_data(head);

	add_at_pos(head,130,10);
	print_data(head);

	return 0;
}