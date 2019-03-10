#include<stdio.h>
#include<sys/resource.h>
#include<signal.h>
void func(int n)
{
printf("in function...%d\n",getpid());
}
main()
{
int ret;
struct rlimit v;
signal(SIGXCPU,func);
printf("in main...\n");
printf("%u\n",getpid());
getrlimit(RLIMIT_CPU,&v);
printf("%u\n",v.rlim_cur);
printf("%u\n",v.rlim_max);
v.rlim_cur =10;
v.rlim_max=20;
ret=setrlimit(RLIMIT_CPU,&v);
printf("%u\n",v.rlim_cur);
printf("%u\n",v.rlim_max);
//func();
while(1);
}
