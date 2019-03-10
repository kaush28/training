#include"headers.h"
main(int n,char **p)
{
struct stat v1,v2;

if(stat(p[1],&v1)==-1)
perror("stat");
else
stat(p[2],&v2);
printf("time1: %u\n",v1.st_atime);
printf("time2: %u\n",v2.st_atime);
if(v1.st_atime>v2.st_atime)
printf("v1 is access before v2.\n");
else if(v1.st_atime<v2.st_atime)
printf("v1 is access after v2.\n");
else
printf("access time for both are same.\n");
}
