#include<stdio.h>
main()
{
int num,a,b=0,c;
printf("enter the number: ");
scanf("%d",&num);
a=num;
while(a>0)
{
c=a%10;
b=(b*10)+c;
a=a/10;
}
printf("%d\n",b);
}
