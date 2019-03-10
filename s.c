#include<stdio.h>
main()
{
int a,b;
for(a=1;a<=15;a++)
{
for(b=1;b<=18;b++)
{
if((a==4||a==5||a==6)&&(b>=5)) break;
printf("_");
}
printf("\n");
}
}
