#include<stdio.h>
#include<sys/types.h>
int cnt=0;
main()
{
/*
printf("1:%d\n",getpid());
fork();
printf("2:%d\n",getpid());
fork();
printf("3:%d\n",getpid());
fork();
printf("4:%d\n",getpid());
*/
int n,i;
printf("n=");
scanf("%d",&n);
for(i=0;i<n;i++)
{
cnt++;
fork();
printf("%d....%d\n",cnt,getpid());
for(i=0;i<n;i++)
{
if(fork()==0)
printf("%d\n",getpid());
}
}
}








