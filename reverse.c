#include<stdio.h>
main()
{
int v=-1,bit,a,b,c,left,right;
bit=31;
while(bit>=0)
{
printf("%d",(v>>bit)&1);
bit--;
}
printf("\n");
//************************

//***************************
bit=31;
while(bit>=0)
{
printf("%d",(c>>bit)&1);
bit--;
}
}
