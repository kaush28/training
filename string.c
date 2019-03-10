#include<stdio.h>
void str_count(char *p)
{
int i,ch=0,sp=0,no=0;
for(i=0;p[i];i++)
{
if(p[i]>=97 && p[i]<=122)
ch++;
else if(p[i])
}
}
main()
{
char str[200];
int ch,i,sp,no;
printf("enter the strings: ");
scanf("%[^\n]s",str);
str_count(&str);
}
