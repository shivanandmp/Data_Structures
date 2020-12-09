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

void add_to_empty(struct node **head,struct node **tail,int data){
	if((*head) != NULL){
		printf("List Is Not Empty: Use add_at_end or add_at_front To Add To A Non-Empty List\n");
	} else{
		struct node *temp = malloc(sizeof(struct node));
		temp->prev = NULL;
		temp->next = NULL;
		temp->data = data;
		(*head) = temp;
		(*tail) = (*head);
	}
}

void add_at_end(struct node **tail, int data){

	if((*tail) == NULL){
		printf("List Is Empty: Use add_to_empty To Add To An Empty List\n");
	} else{
		struct node *temp = malloc(sizeof(struct node));
		(*tail)->next = temp;
		temp->prev = (*tail);
		temp->data = data;
		temp->next = NULL;
		(*tail) = temp;
	}
}

void add_n_at_end(struct node **tail, int data, int n){
	for ( ; data <= n; ++data)
	{
		add_at_end(tail,data);
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

void add_at_nth_position(struct node *ptr, int n, int data){
	if(ptr == NULL){
		printf("List Is Empty: Use add_to_empty To Add To An Empty List\n");
	} else{
		struct node *temp = malloc(sizeof(struct node));
		temp->prev = NULL;
		temp->data = data;
		temp->next = NULL;
		for (int i = 1; i < n-1; ++i)
		{
			ptr= ptr->next;
		}
		temp->prev = ptr;
		temp->next = ptr->next;
		ptr->next = temp;
		temp->next->prev = temp;

		printf("%d Added At Position %d\n",data,n );
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
	struct node *tail = head;

	print(head);
	add_at_end(&tail,67);
	print(head);
	add_at_end(&tail,78);

	add_to_empty(&head,&tail,55);
	print(head);
	add_at_end(&tail,56);
	print(head);
	add_at_end(&tail,57);
	print(head);

	add_at_front(&head,54);
	print(head);
	add_at_end(&tail,58);
	print(head);

	add_to_empty(&head,&tail,87);
	print(head);

	del_list(&head);
	print(head);
	del_list(&head);

	add_to_empty(&head,&tail,55);
	print(head);
	add_at_end(&tail,56);
	print(head);
	add_at_end(&tail,57);
	print(head);
	add_at_front(&head,54);
	print(head);
	add_at_end(&tail,58);
	print(head);
	add_to_empty(&head,&tail,87);
	print(head);

	add_at_end(&tail,59);
	print(head);

	add_n_at_end(&tail,60,65);
	print(head);

	add_at_end(&tail,66);
	print(head);

	add_at_nth_position(head,4,100);
	print(head);

	return 0;
}