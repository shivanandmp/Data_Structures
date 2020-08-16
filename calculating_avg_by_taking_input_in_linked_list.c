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

float average(struct node *ptr,int n) {
    int avg =0;
    if(ptr == NULL) return avg;
    
    avg += ptr->data;
    while(ptr->link->link != NULL) {
        ptr = ptr->link;
        avg += ptr->data;
    }
    ptr = ptr->link;
    avg += ptr->data;
    return (float)avg/n;
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
	
	float avg = average(head,n);
	printf("%lf",avg);
	return 0;
}