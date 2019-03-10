#include<stdio.h>
main()
{
int a,b,n,c,d;
printf("enter the value of n: ");
scanf("%d",&n);
for(a=-n;a<=n;a++)
{
c=a;
if(c<0) (c=-c);
for(b=0;b<=n;b++)
{
//d=b;
//if(d<0) (d=-d);
if(b<(n-c))
{
printf(" ");
}
else
{
printf("* ");
}
}
printf("\n");
}
}
