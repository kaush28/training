#include<stdio.h>
main()
{
int a=1, b=0, c=0, d;
printf("%d %d %d \n",a,b,c);
d=a&&b||c;
printf("%d %d %d %d\n",a,b,c,d);
d=a||b&&c;
printf("%d %d %d %d\n",a,b,c,d);

}
