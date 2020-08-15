// just like variables we can also pass structure members as arguments

// instead of structure members we can also pass structure variables as arguments
// unlike arrays, name of structure variables are not pointers

// if the size of the structure is very large then passing the copy of whole structure is not efficient so we can pass the address of the structure
// we can use the (->) arrow operator to access the structure members in the called function

// returning a structure variable from a function is similar to returning a variable from a function

// returning a pointer to a structure from a function : refer part5 video or the example

// passing array of structures : part6 video or example problem

// self referential structures : refer video or the program


#include <stdio.h>

struct point
{
	int x;
	int y;
};

void print(struct point *ptr){
	printf("%d %d\n", ptr->x,ptr->y); // accessing struct members using arrow opeartor
}

	// RETURNING A STRUCTURE FROM A FUNCTION

struct point edit(struct point p){
	(p.x)++;
	p.y += 5;
	return p;
}

	// ACCESSING STRUCT MEMBERS USING ARROW OPERATOR

void edit2(struct point *p){
	(p->x)++;
	p->y += 5;
}

int main(){
	struct point p1 = {23,45};
	struct point p2 = {43,76};
	print(&p1);
	print(&p2);

	p1 = edit(p1);
	edit2(&p2);

	printf("\n");
	print(&p1);
	print(&p2);

	return 0;
}