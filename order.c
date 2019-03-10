#include<stdio.h>
#include<string.h>
order(char *p)
{
int i;
char s[20];
for(i=0;p[i];i++)
{
if(p[i]>p[i+1])
{
s[0]=p[i];
p[i]=p[i+1];
p[i+1]=s[0];
}
}
}
main()
{
char s[20];
printf("enter the string: ");
scanf("%[^\n]s",s);
order(s);
printf("the ordered string is %s",s);
}
