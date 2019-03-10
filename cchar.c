#include<stdio.h>
main()
{
	char v=100;
printf("v=%c %d\n",v,v);
v='a';
printf("v=%c %d\n",v,v);
v=v-33;
printf("v=%c %d\n",v,v);
printf("enter a character:",v);
v=getchar();
printf("v=%c %d\n",v,v);
}
