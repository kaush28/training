#include<stdio.h>
#include<string.h>
void swap_string(char *str1,char *str2)
{
int n;
n=strlen(str2);
char str3[20];
strcpy(str3,str1);
strcpy(str1,str2);
strcpy(str2,str3);
/***
strcat(str2,str1);
//strncpy(str1,str2,n);
memmove(str1,str2,n);
//strcpy(str2,str2+n);
memmove(str2,str2+n,strlen(str2+n)+1);
***/
}
main()
{
char s1[20],s2[20];
printf("enter the 1st string: ");
gets(s1);
printf("enter the 2nd string: ");
gets(s2);
swap_string(s1,s2);
printf("s1=%s, s2=%s\n",s1,s2);
}
