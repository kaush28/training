#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
main(int n,char **p)
{
printf("%d.....%d..\n",getpid(),getppid());
if(fork()==0)
{
//system(p[1]);
execlp("ls","ls",NULL);
}
else
{
//system(p[2]);
if(fork()==0)
{
execlp("cal","cal",NULL);
}
else
{
if(fork()==0)
execlp("ps","ps",NULL);
//system(p[3]);
}
}
printf("exiting...%d\n",getpid());
}
