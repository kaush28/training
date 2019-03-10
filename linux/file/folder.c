#include"headers.h"
//#include<linux/dirent.h>
main()
{
int i=0,j;
char name[20];
struct stat v;
DIR *dp;
struct dirent *ptr;
struct timeb tm;
dp=opendir("./");
while(ptr=readdir(dp))
{
if(!((strcmp(ptr->d_name,".")==0) || (strcmp(ptr->d_name,"..")==0)))
{
stat(ptr->d_name,&v);
printf("%s:",ptr->d_name);
printf("%u\n",v.st_size);
j=v.st_size;
if(i<j)
{
i=j;
strcpy(name,ptr->d_name);
}
}
}
printf("largest file is: %s\n",name);

}
