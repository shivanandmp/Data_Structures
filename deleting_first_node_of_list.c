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

void add_at_end(struct node* *ptr, int data) { // this function adds without traversing the whole list , so it is faster than the previous one
	struct node *temp = (struct node *)malloc(sizeof(struct node));

	temp->data = data;
	temp->link = NULL;

	(*ptr)->link = temp;
	*ptr = temp;
}

void delete_first(struct node* *head) {
	if(*head == NULL) {
		printf("List Is Already Empty\n");
	}
	else {
		struct node *temp = *head;
		*head = (*head)->link;
		free(temp);
		temp = NULL;
	}
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
	struct node *head = malloc(sizeof(struct node));
	head->data = 65;
	head->link = NULL;

	struct node *ptr = head;

	add_at_end(&ptr,67);
	add_at_end(&ptr,69);

	add_at_begin(&head,61);
	add_at_pos(head,63,2);

	delete_first(&head);

	print_data(head);
	return 0;
}