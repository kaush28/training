#include<stdio.h>
#include<math.h>
main()
{
float a,b,c;
for(a=0;a<=9;a++)
{
b=0.0;
while(b<1)
{
c=sqrt(a+b);
printf("%f",c);
b+=0.1;
}
printf("\n");
}
}
