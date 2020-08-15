#include <stdio.h>
#include <stdlib.h>

struct point
{
	int x;
	int y;
};

struct point* fun(int a, int b)
{
	struct point *ptr = (struct point *)malloc(sizeof(struct point)); // using malloc because we want to allocate heap memory
	ptr->x = a;
	ptr->y = b+5;
	return ptr; // the address (or variable) allocated by malloc is not destroyed(deallocated) after function completion so we can pass it to main function
				// where as memory allocated in stack automatically gets deallocated after function completion

	// there is no need to deallocate (free()) memory here as we are passing the address to main function and we are deallocating it there
};

void print(struct point p){
	printf("%d %d\n", p.x,p.y);
}

int main(){
	struct point *p1,*p2; // declared two pointers of type struct point

	p1 = fun(2, 3); // we are receing the address and storing it in p1 and p2
	p2 = fun(6, 9);

	print(p1); // printing by pass by value the whole structure
	print(p2);

	free(p1);
	free(p2); // we are deallocating p1 and p2 here

	return 0;
}