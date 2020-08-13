// Data: the quantities, character or symbols on which operations are preformed by a computer, which may be stored and transmited in the form of electrical signals and recorded on magnetic, optical or mechanical recording media

// Information: if data is arranged in a systematic and understandeable way it becomes information

// Data Structure: systematic way to organise data so that it can be used efficiently(in terms of time and space)


// DATA TYPES :
				// it defines a certain domain of values  and operations allowed on them

// USER DEFINED DATA TYPE:
				// operations and values of user definde data types are not defined by the language it self but is specified by the user
				// eg. structure, union and enumeration

// ABSTARCT DATA TYPES :  
				// ADTs are like user defined data types which define operations on values using functions without specifying what is there isnide the function and how the operations are performed

				// Example: stack ADT
						// a stack consists of elements of same data type arranged in a sequential order
						// Operations: initialize() : initialises the stack to be empty
									// push() :  insert an element into the stack
									// pop() : delete an element from the stack 
									// isEmpty() : to check if stack is empty
									// isFull() : to check if stack is full

// ADT is like a blackbox which hides the innner structure and design of the data type from the user
// there are multiple ways to implement an ADT
// Eg. a stck ADT can be implemented using arrays or linked lists


// The progarm which uses data structure is called a client program. It has access to the ADT i.e. interface
// The program which implements the data structure is known as the implementation

// ADVANTAGE: if someone wants to use push() and pop() operations, they can do so without knowing its implementation
				// the user doesn't have to worry about how the operation works

			// also if in future, the implmentation of stack is changed from array to linked list, then the client program will work in the same way without being affected


// ADT provides ABSTRACTION i.e. hiding details from the user

// a data structure is used to implement an ADT
// ADT tells us what is to be done and Data Structures tell us how to do it


// Which Data Type to use for an ADT
									// in reality different implementations of ADT can be compared for time and space efficiency. The one best suited according to the current requirement of the user will be selected


// Proper choice of Data Structures can make program efficient in terms of space and time
// One implementation can be sued by multiple client programs
// It provides a level of Abstraction