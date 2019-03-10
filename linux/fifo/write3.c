#include"headers.h"
void f1(int n)
{
printf("no reader to read the data.\n");
exit(0);
}
main()
{
int n[3];
int fd;
signal(13,f1);
char wr_buf[20];
fd=open("fifo1",O_WRONLY|O_CREAT,0777);
//while(1)
//{
printf("enter string:\n");
gets(wr_buf);
write(fd,wr_buf,20);
//}
//close(fd);
fd=open("fifo2",O_RDONLY);
read(fd,n,12);
printf("character=%d\nnumber=%d\nspecial char=%d\n",n[1],n[0],n[2]);
close(fd);
}
