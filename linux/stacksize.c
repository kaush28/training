#include<stdio.h>
//#include<sys/time.h>
#include<sys/resource.h>
int cnt=0;
//int setrlimit(int,struct rlimit *);
void func(void)
{
cnt++;
int k[1000000];
printf("in func...%u.....cnt=%d\n",getpid(),cnt);
if(cnt<20)
func();
}
//struct rlimit
//{
//int v.rlim_cur;
//int v.rlim_max;
//};
main()
{
int ret;
struct rlimit v;
printf("in main...\n");
printf("%d\n",getpid());
getrlimit(RLIMIT_STACK,&v);
printf("%u\n",v.rlim_cur);
printf("%u\n",v.rlim_max);
v.rlim_cur *=8;
ret=setrlimit(RLIMIT_STACK,&v);
func();
}
