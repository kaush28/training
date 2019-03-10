#include<stdio.h>
#include<math.h>
main()
{
int num,i,max;
printf("enter a number: ");
scanf("%d",&num);
max=sqrt(num);
i=2;
while(i<=max)
{
if(num%i==0)
{
break;
}
i++;
}
if(i==(max+1))
{
printf("prime number\n");
}
else
{
printf("not a prime number\n");
}
}


