#include<stdio.h>

int main()
{
	int a1,a2,b1;
	a1 = 100;
	a2 = 18;
	b1 = 99;
	int * a;
	int * b;

	b = &b1;
	a = &a1;
	
	a = b;

	a = &a2;

	printf("&a is %d\n&b is %d\n", *a, *b);

	return 0;
}
