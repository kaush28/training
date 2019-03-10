#include<stdio.h>
int sum(int,int);
main()
{
int a,b,result;
printf("enter two integers: ");
scanf("%d %d",&a,&b);
result=sum(a,b);
printf("result=%d\n",result);
}
