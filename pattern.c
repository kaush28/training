#include<stdio.h>
main()
{
int a,b,c=1,n=6;
for(a=1;a<=n;a++)
{
//for(b=1;b<=(n-a);b++)
//{
//printf(" ");
//}
if(a%2!=0)
{
c=1;
}
for(b=1;b<=a;b++)
{
printf("%d",c);
c=(c==0);
}
printf("\n");
}
}
