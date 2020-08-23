#include <stdio.h>
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

void delete_end(struct node *head, struct node **ptr) {
	*ptr = head;
	if(head == NULL) printf("List is already empty\n");
	else if(head->link == NULL) {
		free(head);
		head = NULL;
		*ptr = head;
	}
	else{
		while((*ptr)->link->link != NULL){
			(*ptr) = (*ptr)->link;
		}
		free((*ptr)->link);
		(*ptr)->link = NULL;
	}
}

int main(int argc, char const *argv[])
{
	struct node *head = malloc(sizeof(struct node));
	head->data = 62;
	head->link = NULL;
	struct node* ptr = head;

	add_at_end(&ptr,63);
	add_at_end(&ptr,64);
	add_at_end(&ptr,65);

	delete_end(head,&ptr);

	add_at_end(&ptr,67);
	print_data(head);

	add_at_end(&ptr,68);
	add_at_end(&ptr,69);
	delete_end(head,&ptr);
	print_data(head);

	return 0;
}