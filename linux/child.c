#include<stdio.h>
#include<sys/types.h>
main()
{
printf("in main.....%d.....%d\n",getpid(),getppid());
if(fork()==0)
{
printf("in child.....%d.....%d\n",getpid(),getppid());
sleep(5);
printf("in child.....%d.....%d\n",getpid(),getppid());
}
else
printf("in father.....%d.....%d\n",getpid(),getppid());

}
