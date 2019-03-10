#include<stdio.h>
#include<sys/types.h>
main()
{
printf("fork...\n");
if(fork())
printf("in if...%u.....%u\n",getpid(),getppid());
else
printf("in else...%u.....%u\n",getpid(),getppid());
}
