#include<stdio.h>
#include<string.h>
void asciiname(char *p1,int *p2)
{
int i,j;
for(i=0;p1[i];i++)
j=p1[i];
printf("%u\n",&j);
p2[i]=j;

}
main()
{
char s1[20];
int s2[100];
printf("enter your name: ");
scanf("%[^\n]s",s1);
asciiname(s1,s2);
//printf("ascii value of the name is %s\n",s2);
}
