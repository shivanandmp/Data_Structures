#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

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
	ptr = add_at_end(ptr,36); // ptr is always stroing the last node address

	print_data(head);

	ptr = add_at_end(ptr,76);
	ptr = add_at_end(ptr,57);
	print_data(head);

	return 0;
}