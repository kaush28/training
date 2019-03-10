#include<stdio.h>
void reverse(int,int);
main()
{
int num,bit,option;
char ch;
printf("enter the number: ");
scanf("%d",&num);
printf("\n1 for bit reverse\n2 for digit reverse\n");
scanf(" %d",&option);
reverse(num,option);
}
void reverse(int data,int option)
{
int a=0,left,right,x,y,z;
if(option==1)
{
left=31;
while(left>=0)
{
printf("%d",(data>>left)&1);
left--;
}
printf("\n");
left=31,right=0;
while(left>right)
{
x=(data>>left)&1;
y=(data>>right)&1;
if(x!=y)
{
data^=(1<<left);
data^=(1<<right);
}
left--;
right++;
}
left=31;
while(left>=0)
{
printf("%d",(data>>left)&1);
left--;
}
printf("\n");
}
else
{
while(data)
{
z=data%10;
a=(a*10)+z;
data=data/10;
}
printf("%d\n",a);
}
}

