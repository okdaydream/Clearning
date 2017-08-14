#include<stdio.h>
#include<string.h>

int main(int argc, char * argv[])
{
	string a = argv[1];
	string b = argv[2];

	if(a==b)
	{
		printf("a==b is ture!");
	}

	if((a&0xffff)==(b&0xffff))
	{
		printf("a&0xffff == b&0xffff");
	}

	return 0;
}
