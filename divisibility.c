#include<stdio.h>
main()
{
int i,count=0;
printf("numbers not divisible either by 2 or 3 are: ");
for(i=1;i<=100;i++)
{

if((i%2!=0)&&(i%3!=0))
{
count++;
printf("%d,",i);
}

}
printf("\ntotal number not divisible by either 2 or 3 are %d\n",count);
}
