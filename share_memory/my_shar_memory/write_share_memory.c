/*******************************************************
*	write data in share memory
*	qiuguizhu
*	2017/08/21
*******************************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include"shm_shmdata.h"

#define WRITE_SIZE	1024

//static int shmid;
static char * shmaddr;

int main()
{
	shmid = shmget(IPC_PRIVATE, WRITE_SIZE, IPC_CREAT | 0600);

	if(shmid < 0)
	{
		perror("get share memory ipc_id error!\n");
		return -1;
	}
	
	shmaddr = (char *)shmat(shmid, NULL, 0);
	
	scanf("%s",shmaddr);

	printf("%s\n",shmaddr);

	shmdt(shmaddr);

	return 0;
}


