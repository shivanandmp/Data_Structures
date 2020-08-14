// free() is used to release the dynamically allocated memory in heap
// Syntax: void free(ptr)

// it is the programmers responsibility to release the emmory after use, as it is not released on its own


#include <stdio.h>
#include <stdlib.h>

int* input(){
	int *ptr;
	ptr = (int*)malloc(5*sizeof(int)); // malloc allocates memory in heap, and is not destroyed after the completio of function
	for (int i = 0; i < 5; ++i)
	{
		*(ptr+i) = i;
	}
	return ptr;
}

int main(int argc, char const *argv[])
{
	int *ptr,sum=0;
	ptr = input();
	for (int i = 0; i < 5; ++i)
	{
		sum += *(ptr+i);
	}
	printf("%d\n", sum); // 0 +1 + 2+ 3+ 4= 10

	// now we need to release the memory
	free(ptr); // deallocate the memory
	ptr = NULL; // to avoid ptr being a dangling pointer
	return 0;
}