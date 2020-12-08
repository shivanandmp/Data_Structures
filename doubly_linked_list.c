#include <stdio.h>
#include <stdlib.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

void print(struct node *ptr){
	if(ptr == NULL){
		printf("List Is Empty: Please Add Something To Print\n");
	} else{
		do{
			printf("%d ",ptr->data);
			ptr = ptr->next;
		}while(ptr != NULL);
		printf("\n");
	}
}

void add_to_empty(struct node **head,struct node **ptr,int data){
	if((*head) != NULL){
		printf("List Is Not Empty: Use add_at_end or add_at_front To Add To A Non-Empty List\n");
	} else{
		struct node *temp = malloc(sizeof(struct node));
		temp->prev = NULL;
		temp->next = NULL;
		temp->data = data;
		(*head) = temp;
		(*ptr) = (*head);
	}
}

void add_at_end(struct node **ptr, int data){

	if((*ptr) == NULL){
		printf("List Is Empty: Use add_to_empty To Add To An Empty List\n");
	} else{
		struct node *temp = malloc(sizeof(struct node));
		(*ptr)->next = temp;
		temp->prev = (*ptr);
		temp->data = data;
		temp->next = NULL;
		(*ptr) = temp;
	}
}

void add_at_front(struct node **head, int data){

	if((*head) == NULL){
		printf("List Is Empty: Use add_to_empty To Add To An Empty List\n");
	} else{
		struct node *temp = malloc(sizeof(struct node));
		temp->prev = NULL;
		temp->data = data;
		temp->next = NULL;
		temp->next = (*head);
		(*head)->prev = temp;
		(*head) = temp; 
	}
}

void del_list(struct node **head){
	if(*head == NULL){
		printf("List Couldn't Be Deleted: List Is Already Empty\n");
	} else{
		struct node *temp = *head;
		while(temp != NULL){
			temp = temp->next;
			free(*head);
			*head = temp;
		}
		printf("\nList Deleted Succesfully\n\n");
	}
}

int main(){
	struct node *head = NULL;
	struct node *ptr = head;

	print(head);
	add_at_end(&ptr,67);
	print(head);
	add_at_end(&ptr,78);

	add_to_empty(&head,&ptr,55);
	print(head);
	add_at_end(&ptr,56);
	print(head);
	add_at_end(&ptr,57);
	print(head);

	add_at_front(&head,54);
	print(head);
	add_at_end(&ptr,58);
	print(head);

	add_to_empty(&head,&ptr,87);
	print(head);

	del_list(&head);
	print(head);
	del_list(&head);

	add_to_empty(&head,&ptr,55);
	print(head);
	add_at_end(&ptr,56);
	print(head);
	add_at_end(&ptr,57);
	print(head);
	add_at_front(&head,54);
	print(head);
	add_at_end(&ptr,58);
	print(head);
	add_to_empty(&head,&ptr,87);
	print(head);

	return 0;
}