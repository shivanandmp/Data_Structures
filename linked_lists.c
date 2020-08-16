#include <stdio.h>

// it is a type of list made up of nodes
// in a linked list, the elements are NOT stored in consecutive order

// ARRAY is the SEQUENTIAL REPRESENTATION of lists
// LINKED LIST is the LINKED REPRESENTATION of lists, the nodes are scattered

// TYPES

	// 1. Single Linked List : navigation is forward only
	// 2. Doubly Linked List : forward and backward navigation is possible
	// 3. Circular Linked List : last element is linked to the first element 


// SINGLE LINKED LISTS: a list made up of nodes that consists two parts(data and link)
	// node in linked list is just like an element of array
	// data contains the actual data of the node
	// link contains the address of the next node of the list
	// link acts as a pointer to the next element in the list

	// to access the first node, we create a pointer and call it HEAD