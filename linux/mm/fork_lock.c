#include"headers.h"
main()
{
int i,fd,j,n;
char buf[10]="abcdefghij";
//struct flock v; 
fd=open("datafile1",O_RDWR|O_APPEND);
printf("enter ther value of n: ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
if(fork()==0)
continue;
}
//v.l_type=F_WRLCK;
//v.l_whence=0;
//v.l_start=0;
//v.l_len=100;
//fcntl(fd,F_SETLKW,&v);
for(j=0;buf[j];j++)
{
write(fd,buf+j,1);
sleep(1);
}
exit(0);
//v.l_type=F_UNLCK;
//fcntl(fd,F_SETLK,&v);
}
