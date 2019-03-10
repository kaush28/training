#include<stdio.h>
#include<string.h>
void rm_nonalphabet(char *p)
{
int i;
for(i=0;p[i];i++)
{
if(p[i]<'a'||p[i]>'z')
{
memmove(p+i,p+i+1,strlen(p+i+1)+1);
i--;
}
}
}
main()
{
char s1[100];
printf("enter the string: ");
scanf("%[^\n]s",s1);
rm_nonalphabet(s1);
printf("the result is %s\n",s1);
}
