#include "time.h"
#include "stdio.h"

int main (void)
{
	struct tm * ptr;
	time_t lt;
	char str[80];
	
	lt = time(NULL);
	ptr = localtime(&lt);
	
	strftime(str, sizeof(str), "It is now:	%b %d %Y %H:%M:%S",ptr);
	printf("%s\n", str);
	
	return 0;
}

