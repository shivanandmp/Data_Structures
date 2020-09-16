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

void del_list(struct node **head) {
	struct node *temp = *head;

	while(*head != NULL){
		temp = temp->link;
		free(*head);
		*head = temp;
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
	add_at_end(&ptr,67);
	print_data(head);

	del_list(&head);
	if(head == NULL){
		printf("Linked List Is Emptied\n");
	} else{
		printf("Program Fucked Up\n");
	}
	return 0;
}