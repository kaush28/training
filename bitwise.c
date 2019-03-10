#include<stdio.h>
main()
{
int a=25, b=10, c=13, d;
printf("%d %d %d\n",a,b,c);
a^=b^=a^=b;
printf("%d %d\n",a,b);
}
