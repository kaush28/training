#include<stdio.h>
main()
{
double no;
char ch;
char *p;
int i,bit;
printf("enter the double no: ");
scanf("%lf",&no);
p=&no;
for(i=7;i>=0;i--)
{
bit=8;
ch=*(p+i);
while(bit>=0)
{
printf("%u",(ch>>bit)&1);
bit--;
}
}
}
