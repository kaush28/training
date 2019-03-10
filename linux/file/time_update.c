#include"headers.h"
main(int n,char **p)
{
struct utimbuf v1,v2;
/*
struct stat v1,v2;
stat(p[1],&v1);
stat(p[2],&v2);
printf("time1:%u\n",v1.st_atime);
printf("time2:%u\n",v2.st_atime);
*/
utime(p[1],&v1);
utime(p[2],&v2);
printf("%u---%u\n",v1.actime,v1.modtime);
printf("%u---%u\n",v2.actime,v2.modtime);
if(v1.actime>v2.actime)
v2.actime=v1.actime;
else
v1.actime=v2.actime;
if(v1.modtime>v2.modtime)
v2.modtime=v1.modtime;
else
v1.modtime=v2.modtime;
printf("%u---%u\n",v1.actime,v1.modtime);
printf("%u---%u\n",v2.actime,v2.modtime);

}
