#include<stdio.h>
#include<stdlib.h>
main()
{
srand(getpid());
int ch[100],n,i,count=0,j,vowel[5]={'A','E','I','O','U'};
n=sizeof(ch)/sizeof(ch[0]);
rand();
printf("enter 10 characters: ");
for(i=0;i<n;i++)
{
ch[i]=rand()%25+65;
printf("%c,",ch[i]);
}
printf("\n");
for(i=0;i<n;i++)
{
for(j=0;j<5;j++)
{
if(ch[i]==vowel[j])
{
count++;
}
}
}
printf("the number of vowels is %d\n",count);
}
