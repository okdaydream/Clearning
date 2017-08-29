/******************************************************
*	get serial port information and write it down
*	qiuguizhu
*	2017/08/27
******************************************************/

#include<stdio.h>	/*base input output*/
#include<stdlib.h>	/*base function library*/
#include<unistd.h>	/*unix base function define*/
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>	/*file control define*/
#include<termios.h>	/*PPSIX terminal control define*/
#include<errno.h>	/*erro define*/

#define	FALSE	-1
#define	TRUE	0
#define serPort	"/dev/ttyS0"

struct termios options;

/*open serial port*/
int OpenDev(char * Dev)
{
	int fd = open(Dev, O_RDWR);
	if(-1 == fd)
	{
		perror("Can't open serial port");
		return FALSE;
	}
	else
		return fd;
}

/*set the rate of baud*/
int set_Speed(int fd, int baud_rate)
{
	/*get the current option for the port*/
	tcgetattr(fd, &options);

	/*set the baud rates to 19200*/
	cfsetispeed(&options, B19200);
	cfsetospeed(&options, B19200);

	/*enable the receiver and set local mode*/
	options.c_cflag |= (CLOCAL | CREAD);

	/*set the new options for the port*/
	tcsetattr(fd, TCSANOW, &options);
}
int set_Parity(int fd,int databits,int stopbits,int parity)
{ 
    struct termios options; 
    if  ( tcgetattr( fd,&options)  !=  0) { 
        perror("SetupSerial 1");     
        return(FALSE);  
    }
    options.c_cflag &= ~CSIZE; 
    switch (databits) /*设置数据位数*/
    {   
    case 7:        
        options.c_cflag |= CS7; 
        break;
    case 8:     
        options.c_cflag |= CS8;
        break;   
    default:    
        fprintf(stderr,"Unsupported data size\n"); return (FALSE);  
    }
switch (parity) 
{   
    case 'n':
    case 'N':    
        options.c_cflag &= ~PARENB;   /* Clear parity enable */
        options.c_iflag &= ~INPCK;     /* Enable parity checking */ 
        break;  
    case 'o':   
    case 'O':     
        options.c_cflag |= (PARODD | PARENB); /* 设置为奇效验*/  
        options.c_iflag |= INPCK;             /* Disnable parity checking */ 
        break;  
    case 'e':  
    case 'E':   
        options.c_cflag |= PARENB;     /* Enable parity */    
        options.c_cflag &= ~PARODD;   /* 转换为偶效验*/     
        options.c_iflag |= INPCK;       /* Disnable parity checking */
        break;
    case 'S': 
    case 's':  /*as no parity*/   
        options.c_cflag &= ~PARENB;
        options.c_cflag &= ~CSTOPB;break;  
    default:   
        fprintf(stderr,"Unsupported parity\n");    
        return (FALSE);  
    }  
/* 设置停止位*/  
switch (stopbits)
{   
    case 1:    
        options.c_cflag &= ~CSTOPB;  
        break;  
    case 2:    
        options.c_cflag |= CSTOPB;  
       break;
    default:    
         fprintf(stderr,"Unsupported stop bits\n");  
         return (FALSE); 
} 
/* Set input parity option */ 
if (parity != 'n')   
    options.c_iflag |= INPCK; 
tcflush(fd,TCIFLUSH);
options.c_cc[VTIME] = 150; /* 设置超时15 seconds*/   
options.c_cc[VMIN] = 0; /* Update the options and do it NOW */
if (tcsetattr(fd,TCSANOW,&options) != 0)   
{ 
    perror("SetupSerial 3");   
    return (FALSE);  
} 
return (TRUE);  
}

int main(int argc, char **argv)
{
	int fd;
	int nread;
	char buff[512];
	char * dev = serPort;
	fd = OpenDev(dev);
	
	set_Speed(fd, 19200);
	if(set_Parity(fd,8,1,'N') == FALSE)
	{
		printf("set parity error\n");
		return FALSE;
	}

	while(1)
	{
		while((nread = read(fd, buff, 512)) > 0)
		{
			printf("\nLen %d\n", nread);
			buff[nread+1] = '\0';
			printf("\n%s",buff);
		}
	}
	
	close(fd);
	return 0;
}
