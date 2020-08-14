#include <stdio.h>
#include <stdlib.h>

// dangling pointer points to some non existing memory location
// refer to the video again

int *fun(){
	int n = 10;
	return &n; 
} // here this function is returning address of 'n' which no more exists(because n was a local variable)

int main(int argc, char const *argv[])
{
	int *ptr = (int*)malloc(sizeof(int));
	// now ptr is pointing to some memory location(say 1000)

	free(ptr); // here ptr is a dangling pointer
	// because we have deallocated the location(1000) and it does not exist now but still ptr is pointing to that nonexisting location

	// a solution to this is reinitialize it wit NULL
	ptr = NULL; // ptr is no more dangling

	ptr = fun(); // ptr again becomes dangling, because it is receiving the address of a non-existing variable

	// now accessing ptr will throw a segmentation fault (segmentation error is when we are trying to access some illegal memory location)

	return 0;
}