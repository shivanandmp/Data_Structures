#include <stdio.h>

struct abc
{
	int a;
	char b;
};

void print(struct abc arr[]){
	for (int i = 0; i < 2; ++i)
	{
		printf("%d %c\n", arr[i].a, arr[i].b);4
	}
}

int main(){
	struct abc arr[2] = {{1,'A'},{2,'B'}}; // this is an array of two structures
	print(arr);

	return 0;
}