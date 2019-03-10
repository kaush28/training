#include"headers.h"
main()
{
int i=0,fd,n,j;
char buf[10]="1234567890";
//char ch;
//printf("enter the value of n: ");
//scanf("%d",&n);
fd=open("datafile",O_RDWR|O_APPEND);
//if(fork==0)
//{
for(j=0;buf[j];j++)
{
write(fd,buf+j,1);
//printf("%c",buf[j]);
sleep(1);
}
//}
}
