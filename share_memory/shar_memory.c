/**********************************************************
*	share_memory
*	qiuguizhu
*	2017/08/21
**********************************************************/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <error.h>

#define SIZE 1024
int main()
{
	int shmid ;
	char *shmaddr ;
	struct shmid_ds buf ;
	int flag = 0 ;
	int pid ;
	/*创建或返回一个共享内存大小为1024Byte的对象并返回共享内存标识符*/
	shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT|0600 ) ;
	if ( shmid < 0 )
	{
		perror("get shm ipc_id error") ;
		return -1 ;
	}
	/*创建子进程*/
	pid = fork() ;

	/*子进程*/
	if ( pid == 0 )
	{
		/*把共享内存区对象映射到调用进程的地址空间，
			成功返回附加好的共享内存地址*/
		shmaddr = (char *)shmat( shmid, NULL, 0 ) ;
		if ( (int)shmaddr == -1 )
		{
			perror("shmat addr error") ;
			return -1 ;
		}
		strcpy( shmaddr, "Hi, I am child process!\n") ;
		shmdt( shmaddr ) ;
		return 0;
	}
	/*父进程*/
	else if ( pid > 0) {
		sleep(3 ) ;
		flag = shmctl( shmid, IPC_STAT, &buf) ;
		if ( flag == -1 )
		{
			perror("shmctl shm error") ;
			return -1 ;
		}
		printf("shm_segsz =%d bytes\n", buf.shm_segsz ) ;
		printf("parent pid=%d, shm_cpid = %d \n", getpid(), buf.shm_cpid ) ;
		printf("chlid pid=%d, shm_lpid = %d \n",pid , buf.shm_lpid ) ;
		shmaddr = (char *) shmat(shmid, NULL, 0 ) ;
		if ( (int)shmaddr == -1 )
		{
			perror("shmat addr error") ;
			return -1 ;
		}
		printf("%s", shmaddr) ;

		/*断开与共享内存的连接*/
		shmdt( shmaddr ) ;

		/*删除这一片共享内存*/
		shmctl(shmid, IPC_RMID, NULL) ;
	}else{
		perror("fork error") ;

		/*删除这一片共享内存*/
		shmctl(shmid, IPC_RMID, NULL) ;
	}
	return 0 ;
}
