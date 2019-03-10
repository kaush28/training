#include<stdio.h>
int itoa(int i,char *p)
{
int n,no=0;
while(i)
{
n=i%10;
no=(no*10)+n;
i=i/10;
}
//printf("%d",no);
while(no)
{
n=no%10;
p[i]=(n+48);
printf("%s",(p+i));
no=no/10;
i++;
}
}
main()
{
int x,a,b;
char s[10];
printf("enter the number: ");
scanf("%d",&x);
itoa(x,s);
}
