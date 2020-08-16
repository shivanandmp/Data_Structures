#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void list_input(struct node* *ptr,int data) {
	(*ptr)->data = data;

	struct node *current = malloc(sizeof(struct node));
	(*ptr)->link = current;
	current->link = NULL;

	*ptr = current;
}

void print_data(struct node *head){

	if (head == NULL)
	{
		printf("Linked list is empty\n");
	}

	struct node *ptr = NULL;
	ptr = head;
	while(ptr->link != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->link;
	}
	printf("\n");
}

int main() {
	struct node *head = malloc(sizeof(struct node));
	head->link = NULL;
	struct node *ptr = head ;
    
    int n,data;
    printf("Enter The Number OF Elements: ");
    scanf("%d",&n);
    
	for (int i = 0; i < n; ++i)
	{
		printf("Enter Element %d :",i+1);
		scanf("%d",&data);
		list_input(&ptr,data);
	}

	print_data(head);
	
	int avg = average(head);
	printf("%d",avg);
	return 0;
}