// null pointer does not point to any memory location. it represents an invalid memory location

// when a NULL value is assigned to a pointer, then the pointer becomes a NULL pointer

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
	int *ptr = NULL;
	printf("%d\n", ptr);

	int *p;
	p = (int*)malloc(2*sizeof(int));

	if(p == NULL) printf("Memory couldn't be allocated\n");
	else printf("Memory allocated successfully\n");
	return 0;
}

// USES OF NULL POINTER
	// used to initialize a pointer when that pointer is not assigned any valid memory address yet
	// useful for handling errors when using malloc function

// the value of NULL is 0 (ZERO), we can either use NULL or 0 but this 0 is written in context of pointers and is not equivalent to the integer 0
// size of NULL pointer depends on the platform and is similar to the size of normal pointers

// it is a good practice to initialize a pointer as NULL
// it is a good practice to perform NULL check before dereferencing any pointer to avoid surprises