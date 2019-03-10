#include<stdio.h>
#include<stdlib.h>
main()
{
srand(getpid());
int j,n,no[10],max,min,i;
n=sizeof(no)/sizeof(no[0]);
printf("enter 10 numbers: ");
rand();
START:
for(i=0;i<n;i++)
{
no[i]=rand()%10;
}
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(i!=j)
{
if(no[i]==no[j])
goto START;
}
}
}
for(i=0;i<n;i++)
{
printf("%d,",no[i]);
}

max=min=no[0];
printf("\n");
for(i=0;i<n;i++)
{
if(max<no[i])
{
max=no[i];
}
if(min>no[i])
{
min=no[i];
}
}
printf("the maximum and minimum number is %d and %d.\n",max,min);
printf("the indexes for maximum value is: ");
for(i=0;i<n;i++)
{
if(max==no[i])
{
printf("no[%d],",i);
}
}
printf("\nthe indexes for minimum value are: ");
for(i=0;i<n;i++)
{
if(min==no[i])
{
printf("no[%d],",i);
}
}
printf("\n");
}
