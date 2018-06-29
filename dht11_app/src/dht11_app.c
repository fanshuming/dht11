#include <stdio.h>
#include <curses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(int argc, char **argv)
{
	int fd;
	unsigned int dht11 = 0;
	unsigned int humi,temp;

	//打开温度传感器驱动模块
	fd = open("/dev/dht11", O_RDWR | O_NONBLOCK);
	if (fd < 0)
	{
		printf("can't open /dev/dht11\n");
		return -1;
	}

	read(fd, &dht11, sizeof(dht11));

	temp = dht11>>8;
	humi = dht11 &0x000000ff;
	printf("the current temperature is: %d\n",temp);
	printf("the current humidity is:    %d\n",humi);


	close(fd);
	
	return 0;
}
