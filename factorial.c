#include<stdio.h>
main()
{
int a,b=1,c;
printf("enter the number: ");
scanf("%d",&a);
while(a>=1)
{
b=b*a;
a--;
}
printf("%d\n",b);
}
