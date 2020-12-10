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
		printf("Added at the front of the List (position1)\n");
	}
}

void add_at_nth_position(struct node **head,struct node **tail, int n, int data){
	if((*head) == NULL){
		printf("List Is Empty: Use add_to_empty To Add To An Empty List\n");
	} else{
		if(n <= 1){
			if(n<=0) printf("%d is an invalid position: ",n);
			add_at_front(head,data);
			return;
		}
		struct node *ptr = (*head);
		struct node *temp = malloc(sizeof(struct node));
		temp->prev = NULL;
		temp->data = data;
		temp->next = NULL;
		for (int i = 1; i < n-1; ++i)
		{
			ptr= ptr->next;
			if(ptr == (*tail)){
				(*tail)->next = temp;
				temp->prev = (*tail);
				(*tail) = temp;
				printf("The List Is Shorter Than The Input Position(%d): %d Added At Position %d\n",n,data,i+2 );
				return;
			}
		}
		temp->prev = ptr;
		temp->next = ptr->next;
		ptr->next = temp;
		temp->next->prev = temp;

		printf("%d Added At Position %d\n",data,n );
	}
}

void del_first(struct node **head){
	if(*head == NULL){
		printf("Node Couldn't Be Deleted: List Is Empty\n");
	} else{
		(*head) = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
		printf("First Node Deleted\n");
	}
}

void del_last(struct node **tail){
	if(*tail == NULL){
		printf("Node Couldn't Be Deleted: List Is Empty\n");
	} else{
		(*tail) = (*tail)->prev;
		free((*tail)->next);
		(*tail)->next = NULL;
		printf("Last Node Deleted\n");
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
		printf("List Deleted Succesfully\n\n");
	}
}

void del_nth_node(struct node **head,struct node **tail, int n){
	if((*head) == NULL){
		printf("List Is Empty: Use add_to_empty To Add To An Empty List\n");
	} else{
		if(n <= 1){
			if(n<=0) printf("%d is an invalid position: ",n);
			del_first(head);
			return;
		}
		if((*head)->next == NULL){
			del_list(head);
			return;
		}
		if((*head)->next == *tail && n==2){
			del_last(tail);
			return;
		}
		struct node *ptr = (*head);
		for (int i = 1; i < n-1; ++i)
		{
			ptr= ptr->next;
			if(ptr == (*tail) || ptr->next == (*tail)){
				del_last(tail);
				return;
			}
		}
		ptr->next = ptr->next->next;
		free(ptr->next->prev);
		ptr->next->prev = ptr;
		printf("Node Deleted At Position %d\n",n );
	}
}

void rev_list(struct node **head, struct node **tail){
	struct node *ptr1 = (*head);
	struct node *ptr2 = (*head)->next;
	*tail = *head;

	ptr1->next = NULL;
	ptr1->prev = ptr2;
	while(ptr2 != NULL){
		ptr2->prev = ptr2->next;
		ptr2->next = ptr1;
		ptr1 = ptr2;
		ptr2 = ptr2->prev;
	}
	(*head)=ptr1;
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

	add_at_nth_position(&head,&tail,4,100);
	print(head);

	add_at_nth_position(&head,&tail,18,100);
	print(head);

	add_at_nth_position(&head,&tail,48,10);
	print(head);

	add_at_nth_position(&head,&tail,1,30);
	print(head);

	add_at_nth_position(&head,&tail,1,10);
	print(head);

	add_at_nth_position(&head,&tail,0,10);
	print(head);

	add_at_nth_position(&head,&tail,-5,68);
	print(head);

	add_at_nth_position(&head,&tail,1,50);
	print(head);

	del_first(&head);
	print(head);

	del_last(&tail);
	print(head);

	del_nth_node(&head,&tail,4);
	print(head);

	del_nth_node(&head,&tail,1);
	print(head);

	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	del_nth_node(&head,&tail,4);
	print(head);

	del_nth_node(&head,&tail,6);
	print(head);

	del_nth_node(&head,&tail,6);
	print(head);

	del_nth_node(&head,&tail,4);
	print(head);

	del_nth_node(&head,&tail,2);
	print(head);

	del_nth_node(&head,&tail,1);
	print(head);

	add_at_end(&tail,66);
	add_at_nth_position(&head,&tail,4,100);
	add_at_front(&head,54);

	del_nth_node(&head,&tail,2);
	print(head);
	del_nth_node(&head,&tail,2);
	print(head);

	del_nth_node(&head,&tail,2);
	print(head);
	del_nth_node(&head,&tail,2);
	print(head);

	add_to_empty(&head,&tail,67);
	add_at_end(&tail,68);
	add_at_end(&tail,69);
	add_at_end(&tail,70);
	add_at_end(&tail,71);
	add_at_end(&tail,72);
	add_at_end(&tail,73);
	print(head);

	rev_list(&head,&tail);
	print(head);

	add_at_end(&tail,66);
	add_at_front(&head,74);
	print(head);

	return 0;
}