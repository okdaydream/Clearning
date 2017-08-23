/*************************************************************
*	main appication of test str convert to number 
*	qiuguizhu
*	2017/08/23
************************************************************/
#include<stdio.h>
#include<dlfcn.h>
#include<stdlib.h>

#define LIB_CACULATE_PATH "./str_conver.so"
#define soFun "strConvertNum"

typedef int (*str_conver_FUNC)(char *, int);

int main()
{
	char * str = (char *)malloc(sizeof(char) * 100);
	int slen;
	scanf("%s%d", str, &slen);
	
	void * handle;
	char * error;

	str_conver_FUNC str_fun_ptr = NULL;

	//open dynamic link library
	handle = dlopen(LIB_CACULATE_PATH, RTLD_LAZY);
	if(!handle) {
	fprintf(stderr, "%s\n", dlerror());
	exit(EXIT_FAILURE);
	}
	
	//clear former error
	dlerror();
	
	*(void **) (&str_fun_ptr) = dlsym(handle, soFun);

	printf("%d\n", (*str_fun_ptr)(str,slen));
	
	dlclose(handle);
	exit(EXIT_SUCCESS);
}
