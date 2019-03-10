#include<stdio.h>
#include<string.h>
void rm_space(char *p)
{
int i;
for(i=0;p[i];i++)
{
if(p[i]==' ')
{
if(i==0)
{
memmove(p+i,p+i+1,strlen(p+i+1)+1);
i--;
}
else if((p[i+1])==' ')
{
memmove(p+i,p+i+1,strlen(p+i+1)+1);
i--;
}
else if((p[i+1])=="")
{
memmove(p+1,p+i+1,strlen(p+i+1)+1);
}
}
}
}
main()
{
char s1[120];
printf("enter the string: ");
scanf("%[^\n]s",s1);
rm_space(s1);
printf("the resultant string is %s\n",s1);
}
