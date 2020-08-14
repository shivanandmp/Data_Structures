// malloc is a built in function declared in stdlib.h file
// malloc(memory allocation) is used to dynamically allocate a single large block of contiguous memory according to the size specified
// memory allocated by malloc is initialised to some garbage value

// Synatx: (void*)malloc(size_t size)
// returns a void pointer pointing to the first byte of the allocated memory if success else returns NULL
// size_t is defined as unsigned int

// malloc allocates memory in heap, and is not destroyed after the completio of function

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int *ptr = (int*)malloc(4); // here the malloc allocates a memory space of 4 bytes and returns an int pointer pointing to the location of its first byte
	// malloc alloacets 4 bytes in heap

	int n = 5;
	int *p = (int*)malloc(n*sizeof(int)); // here malloc allocates a memory location for 5 integers (of 5 integer size)

	if(p == NULL){
		printf("%s\n", "Memory Not Available"); // if the pointer is NULL , we will exit the program
		exit(1); // exits the program
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", p+i); // this line will store the values using pointers
		// or // *(p+i) = i;
	}

	for (int i = 0; i < n; ++i)
	{
		printf("%d\t", *(p+i));
	}

	return 0;
}