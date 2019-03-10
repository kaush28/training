#include<stdio.h>
#include<string.h>
void rem_non_alphabet(char *p)
{
int i;
for(i=0;p[i];i++)
{
if((p[i]>='a'&&p[i]<='z')||(p[i]>='A'&&p[i]<='Z'))
;
else
{
memmove(p+i,p+i+1,strlen(p+i+1)+1);
i--;
}
}
printf("%s\n",p);
}
void lower_to_upper(char *p)
{
int i;
for(i=0;p[i];i++)
{
if(p[i]>='a'&&p[i]<='z')
p[i]=p[i]-32;
}
printf("%s\n",p);
}
void sort(char *p)
{
char ch;
int i,j,n;
n=strlen(p);
for(i=n-1;i>0;i--)
{
for(j=0;j<i;j++)
{
if(p[j]>p[j+1])
{
ch=p[j+1];
p[j+1]=p[j];
p[j]=ch;
}
}
}
printf("%s\n",p);
}

main()
{
char s1[100],s2[100];
printf("enter first string: ");
gets(s1);
printf("enter second string: ");
gets(s2);
rem_non_alphabet(s1);
rem_non_alphabet(s2);
lower_to_upper(s1);
lower_to_upper(s2);
sort(s1);
sort(s2);
if(strcmp(s1,s2)==0)
printf("strings are anagram");
else
printf("not anagram");
printf("\n");
}
