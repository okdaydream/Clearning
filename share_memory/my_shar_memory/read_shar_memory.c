/*****************************************
*	read share memory
*	qiuguizhu
*	2017/08/21
*****************************************/

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include"shm_shmdata.h"
#define SIZE 1024
int main()
{
	int flag;
	struct shmid_ds buf;
	shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT|0600 ) ;
	flag = shmctl(shmid, IPC_STAT, &buf);
	char *shmaddr;

	if ( flag == -1 )
	{
		perror("shmctl shm error");
		return -1 ;
	}
	
	printf("shm_segsz =%d bytes\n", buf.shm_segsz );
	//printf("parent pid=%d, shm_cpid = %d \n", getpid(), buf.shm_cpid );
	//printf("chlid pid=%d, shm_lpid = %d \n",pid , buf.shm_lpid );
	shmaddr = (char *) shmat(shmid, NULL, 0 ) ;
                
	if ( (int)shmaddr == -1 )
	{
        	perror("shmat addr error") ;
                return -1 ;
        }
	
	printf("%s\n", shmaddr);
	
	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
