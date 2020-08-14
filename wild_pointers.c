#include<stdio.h>
#include <stdlib.h>

// wild pointers are also known as uninitialized pointers

// these usually point to some arbitrary location and may cause a program to crash or misbehave

int main(int argc, char const *argv[])
{
	int *p;
	*p = 10; // heer p will act as a wild pointer 
			// because we have not initialized it and we are trying to access it through dereference operator

	return 0;
}

// HOW TO AVOID WILD POINTERS:
	// initialise them with the address of a known variable
	// explicitly allocate the memory and put the values in the allocated memory (using malloc)