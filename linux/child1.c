#include<stdio.h>
#include<sys/types.h>
main()
{
printf("in main......%d......%d\n",getpid(),getppid());
/*
if(fork()==0)
{
printf("in child......%d......%d\n",getpid(),getppid());
if(fork()==0)
printf("next child......%d......%d\n",getpid(),getppid());
}
*/
if(fork()==0)
printf("1st child.....%d.....%d\n",getpid(),getppid());
else
{
if(fork()==0)
printf("2nd child.....%d.....%d\n",getpid(),getppid());
}
}
