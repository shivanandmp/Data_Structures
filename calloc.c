// calloc(clear allocation) is used to dynamically allocate multiple blocks of memory

// IT IS DIFFERENT FROM MALLOC IN TWO WAYS
	// calloc needs two arguements instead of just one
	// Syntax:  void *calloc(size_t n, size_t size)  // n is number of blocks and size is size of each block
													// size_t denotes an unsigned integer

	// memory allocated by calloc is initialised to 0 (ZERO)

// both malloc and calloc return NULL when sufficient memory is not available