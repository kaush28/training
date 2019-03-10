#include<stdio.h>
main()
{
int v,p,r,t;
printf("enter the principle amount: ");
scanf("%d",&p);
printf("\nenter the rate of interest: ");
scanf("%d",&r);
printf("\nenter the time period: ");
scanf("%d",&t);
for(;t>0;t--)
{
v=p*(1+r);
p=v;
}
printf("the final amount after %d years is %d",t,v);

}
