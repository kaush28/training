#include<stdio.h>
main(int n,char **p)
{
int i,j,no,k;
volatile int sum=0;
int s[4];
printf("the total data is: %d\n",(n-1));
for(i=1;i<n;i++)
{
no=0;
for(j=0;p[i][j];j++)
{
k=(p[i][j]-48);
no=(no*10)+k;
}
printf("%d",no);
s[i]=no;
}
if(s[2]==-3)
sum=s[1]-s[3];
else if(s[2]==-5)
sum=(s[1]+s[3]);
else if(p[2]=='*')
sum=(s[1]*s[3]);
else if(s[2]==-1)
sum=(s[1]/s[3]);
printf("%d\n",sum);
}
