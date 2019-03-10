#include"headers.h"
main(int n,char **p)
{
struct stat v1,v2;
stat(p[1],&v1);
stat(p[2],&v2);
if(v1.st_ino==v2.st_ino)
{
lstat(p[1],&v1);
lstat(p[2],&v2);
if(v1.st_ino==v2.st_ino)
printf("hard link.\n");
else
printf("soft link.\n");
}
else
printf("no relation.\n");
}
