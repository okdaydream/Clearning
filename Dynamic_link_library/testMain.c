#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

#define LIB_CACULATE_PATH "./libcaculate.so"

typedef int (*CAC_FUNC)(int,int);
int add (int a,int b);
int main(void)
{
	void * handle;
	char * error;
	CAC_FUNC cac_func = NULL;

	handle = dlopen(NULL, RTLD_LAZY);
	if (!handle) {
		fprintf(stderr, "%s\n", dlerror());
		exit(EXIT_FAILURE);
	}

	dlerror();

	* (void **) (&cac_func) = dlsym(handle, "add");
	if((error = dlerror()) != NULL) {
		fprintf(stderr, "%s\n", error);
		exit(EXIT_FAILURE);
	}

	printf("add: %d\n", (*cac_func)(2, 9));
	
	dlclose(handle);
	exit(EXIT_SUCCESS);
}

int add(int a, int b)
{
	return ( a + b);
}
