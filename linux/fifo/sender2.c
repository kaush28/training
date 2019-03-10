///////////////////////fifo full duplex////////////////
#include"headers.h"
main()
{
int fd;
char buf[50];
if(fork())
{
while(1)
{
fd=open("fifo2",O_WRONLY);
gets(buf);
write(fd,buf,50);
}
}
else
{
while(1)
{
fd=open("fifo1",O_RDONLY);
read(fd,buf,50);
puts(buf);
}
}
}
