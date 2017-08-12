#include<stdio.h>

int check_path(const char * path);

int main(void)
{
	int ret = -1;
	const char * path = "/etc/opt";

	ret = check_path(path);
	
	if(ret == 0)
		printf("erro path");
	else
	{
		if(ret==1)
			printf("true path %c \n", *(path+1));
	}
	return 0;
}

int check_path(const char * path)
{
	if(!path)
		return 0;
	if(*path != '/')
		return 0;
	
	return 1;
}
