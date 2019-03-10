#include<stdio.h>
#include<string.h>
void str_search(char *p1,char *p2)
{
int i;
char *n,temp[100];
n=p1;
while(n=strstr(n,p2))
{
//reverse(p2,temp);
//memmove((p1+(n-p1)),temp,strlen(temp));
memset(p1+(n-p1),1,strlen(p2)-1);
n++;
}
}
/*****
void reverse(char *p,char *temp)
{
int i,n,j;
n=strlen(p);
n=n-1;
for(i=n,j=0;j<=n;i--,j++)
{
temp[j]=p[i];
}
temp[j]='\0';
}
*****/
main()
{
char s1[100],s2[100];
int i;
printf("enter the string: ");
gets(s1);
printf("enter the string to search: ");
gets(s2);
str_search(s1,s2);
printf("%s",s1);
printf("\n");
}
