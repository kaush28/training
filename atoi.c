#include<stdio.h>
int atoi(char *p)
{
int i,no=0,r;
for(i=0;p[i];i++)
{
r=p[i];
r=r-48;
no=(no*10)+r;
}
return no;
}
main()
{
char s[20];
int i;
printf("enter the string: ");
scanf("%s",s);
i=atoi(s);
printf("%d\n",i);
}
