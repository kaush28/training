#include<stdio.h>
main()
{
float cost,average,range,min,max,sum=0;
int count=0;
printf("enter the amount for which the computer has been sold: ");
do
{
scanf("%f,",&cost);
if(count==0)
max=min=cost;
if(cost>max)
max=cost;
else if((cost<min)&&cost>0)
min=cost;
sum=sum+cost;
count++;
}
while(cost>0);
count=count-1;
average=(sum/count);
range=max-min;
printf("average=%f,range=%f,min=%f,max=%f,total=%d",average,range,min,max,count);
}
