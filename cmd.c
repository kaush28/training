#include<stdio.h>
main(int n,char **p)
{
int i,j,l=0,s=0,r=0,no=0,real=0,string=0;
printf("the total data given is: %d\n",n);
for(i=0;i<n;i++)
{
printf("the given value at p[%d] is: %s\n",i,p[i]);
}
for(i=1;i<n;i++)
{
l=r=0;
for(j=0;p[i][j];j++)
{
if(p[i][j]>='0'&&p[i][j]<='9')
l++;
else if(p[i][j]=='.')
r++;
}
if(l==(j))
no++;
else if((l==(j-1))&&r==1)
real++;
else
string++;
}
printf("int:%d,real:%d,string:%d\n",no,real,string);
}
