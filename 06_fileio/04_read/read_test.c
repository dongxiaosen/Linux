#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

/*
 *	./read 1.txt
 *	argc = 2
 *	argv[0] = "./open"
 *	argv[1] = "1.txt"
 */

int main(int argc,char ** argv)
{
	int fd;
	int i;
	int read_num;
	unsigned char buf[100] = {0};
	if(argc != 2)
	{
		printf("usage: %s <file>\r\n",argv[0]);	
		close(fd);
		return -1;
	}
	fd = open(argv[1],O_RDONLY);
	if(fd < 0)
	{
		printf("can not open file %s\r\n",argv[1]);
		printf("err: %s\r\n",strerror(errno));
		perror("open");
		close(fd);
		return -1;
		
	}
	printf("fd = %d\r\n",fd);

	//读文件打印
	read_num = read(fd,buf,(sizeof(buf)-1));
	if(read_num < 0)
	{
		perror("read");
		close(fd);
		return -1;
	}else if(read_num == 0){
		close(fd);
		printf("no data\r\n");
		return 0;
	}else{
		buf[read_num - 1] = '\0';
		printf("%s\r\n",buf);
	}
	close(fd);
	return 0;
}



