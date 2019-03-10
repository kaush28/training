#include<stdio.h>
main()
{
printf("%d.....%d\n",getpid(),getppid());
system("ls");
system("cal");
system("./bg&");
printf("exiting from.....%d\n",getpid());
}
