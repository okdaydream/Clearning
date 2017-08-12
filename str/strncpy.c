#include<stdio.h>
#include<string.h>

int main()
{
	char name[] = {"Chinanet"};
	char dest[100] = 
	{'a','l','e',};

	printf("%s\n",dest);

	strncpy(dest, name, 4);

	printf("%s\n",dest);

	return 0;
}
