#include"headers.h"
main(int n,char **p)
{
int i,sum=0,a,b,v;
if(fork()==0)
{
printf("calculating....\n");
a=atoi(p[1]);
b=atoi(p[2]);
printf("%d + %d\n",a,b);
sum=a+b;
exit(sum);
}
else
{
printf("printing....\n");
wait(&sum);
sum>>=8;
printf("total sum is %d\n",sum);
}
}
