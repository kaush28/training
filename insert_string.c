#include<stdio.h>
#include<string.h>
void string_insert(char *s1,char *s2,int p)
{
/***
char s3[20];
strcpy(s3,s1+p);
strcpy(s1+p,s2);
strcat(s1,s3);
***/
strcat(s2,s1+p);
strcpy(s1+p,s2);
}
main()
{
char s1[20],s2[20];
int position;
printf("enter the 1st string: ");
gets(s1);
printf("enter the 2nd string: ");
gets(s2);
printf("enter the position: ");
scanf("%d",&position);
string_insert(s1,s2,position);
printf("the resultant string is %s\n",s1);
}
