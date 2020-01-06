#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main()
{
	int handle=open("c:\\windows\\win.ini",O_RDWR|O_BINARY);

	unsigned char c;
	read(handle, &c, 1);
	close(handle);
	return 0;
}
