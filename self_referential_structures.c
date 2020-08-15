// Self referential structures are those in which one or member (pointer) points to the structure of the same type

#include <stdio.h>

// Example:
struct self
{
	int a;
	struct self *ptr; // this is a pointer capable of storing the address of a structure of type struct self
};

int main(){
	struct self var1;
	struct self var2;

	var1.a = 65;
	var1.ptr = NULL; // we are initialising the ponter to a NULL value

	var2.a = 66;
	var2.ptr = NULL;

	var1.ptr = &var2; // we are storing the address of var2 in the ptr variable of var1
						// we can do this as ptr is a pointer of type struct self (the same type as var2)

	printf("%d %d\n",var1.a , var1.ptr->a );
}

// Self referential structures are useful in linked list