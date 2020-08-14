// void pointer is a pointer which  has no associated data type with it (it can point to any data of any data type and can be typecasted to any type)

// we cannot dereference a void pointer directly, we first have to typecast it

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n= 10;
	void *ptr = &n;
	printf("%d\n", *(int*)ptr);
	return 0;
}

// USE OF VOID POINTERS:
	// malloc and calloc function returns a void pointer. Due to this reason they can allocate a memory location for any type of data
	// malloc and calloc are used to allocate runtime (dynamic) memory