// realloc is used to change the size of the memory block without losing the old data

// Syntax: void *realloc(void* ptr, size_t newSize)

// returns NULL on failure

// we may lose the data when the new size is smaller than the old data
// newly allocated bytes are uninitialised

