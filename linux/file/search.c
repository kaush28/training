#include"headers.h"
main(int n,char **p)
{
DIR *dp;
struct dirent *ptr;
dp=opendir("./");
while(ptr=readdir(dp))
{
if(strstr(dp,p[1])==0)
printf("%s",p[1]);
}
close dir(dp);
}
