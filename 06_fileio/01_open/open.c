#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>


/*
 *	./open 1.txt
 *	argc = 2
 *	argv[0] = "./open"
 *	argv[1] = "1.txt"
 */

int main(int argc,char ** argv)
{
	int fd;
	if(argc != 2)
	{
		printf("usage: %s <file>\r\n",argv[0]);	
		return -1;
	}
	fd = open(argv[1],O_RDWR);
	if(fd < 0)
	{
		printf("can not open file %s\r\n",argv[1]);
		printf("err: %s\r\n",strerror(errno));
		perror("open");
		
	}
	while(1)
	{
		sleep(20);
	}

	close(fd);
	return 0;
}



