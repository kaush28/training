#include"headers.h"
main()
{
int i=0,fd,n,j;
char buf[10]="1234567890";
struct flock v;
//char ch;
//printf("enter the value of n: ");
//scanf("%d",&n);
fd=open("datafile",O_RDWR|O_APPEND);
//if(fork==0)
//{
v.l_type=F_WRLCK;
v.l_whence=2;
v.l_start=-20;
v.l_len=10;
fcntl(fd,F_SETLKW,&v);
for(j=0;buf[j];j++)
{
write(fd,buf+j,1);
//printf("%c",buf[j]);
sleep(1);
}
v.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&v);
//}
}
