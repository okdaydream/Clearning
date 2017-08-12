#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void printer(char * str)
{
	while(*str!='\0')
	{
		putchar(*str);
		fflush(stdout);
		strr++;
		sleep(1);
	}
	printf("\n");
}

//first pthread
void *thread_fun_1(void * arg)
{
	char *str = "hello";
	printer(str);
}

//second pthread
void *thread_fun_1(void * arg)
{
	char * str = "world";
	printer(str);
}

int main(void)
{
	pthread_t tid1, tid2;

	pthread_create(&tid1, NULL, thread_fun_1, NULL);
	pthread_create(&tid2, NULL, thread_fun_2, NULL):

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);




