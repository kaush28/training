#include"headers.h"
#include<string.h>
#include<pwd.h>
main(int n,char **p)
{
/////////////////////////////////////////////
struct timeb t;
struct tm *tmptr;
char date[20],time[20];
ftime(&t);
tmptr=localtime(&t.time);
strftime(date,20,"%b",tmptr);
strftime(time,20,"%I",tmptr);
/////////////////////////////////////////
struct stat v;
stat(p[1],&v);
printf("mode=%o\n",v.st_mode);
//////////////////////////////////////////////
struct passwd *u;
struct group *g;
///////////////////////////////////////////////////
/*
if(((v.st_mode>>15)&1)==1)
{
if(((v.st_mode>>13)&1))
printf("l");
else
printf("-");
}
*/
if(v.st_mode & S_IFSOCK)
printf("s");
else if(v.st_mode & S_IFLNK)
printf("l");
else if(v.st_mode & S_IFREG)
printf("-");
else if(v.st_mode & S_IFBLK)
printf("b");
else if(v.st_mode & S_IFDIR)
printf("d");
else if(v.st_mode & S_IFCHR)
printf("c");
else if(v.st_mode & S_IFIFO)
printf("f");
/////////////////////////////////////////////////////
if(v.st_mode & S_IRUSR)
printf("r");
else
printf("-");
if(v.st_mode & S_IWUSR)
printf("w");
else
printf("-");
if(v.st_mode & S_IXUSR)
printf("x");
else
printf("-");
if(v.st_mode & S_IRGRP)
printf("r");
else
printf("-");
if(v.st_mode & S_IWGRP)
printf("w");
else
printf("-");
if(v.st_mode & S_IXGRP)
printf("x");
else
printf("-");
if(v.st_mode & S_IROTH)
printf("r");
else
printf("-");
if(v.st_mode & S_IWOTH)
printf("w");
else
printf("-");
if(v.st_mode & S_IXOTH)
printf("x");
else
printf("-");
//////////////////////////////////////////
printf(" %d ",v.st_nlink);
/////////////////////////////////////////
u=getpwuid(v.st_uid);
printf("%s",u->pw_name);
g=getgrgid(v.st_gid);
printf(" %s ",g->gr_name);
////////////////////////////////////////
printf(" %d ",v.st_size);
///////////////////////////////////////
printf(" %s ",date);
printf(" %s ",time);
printf(" %s\n",p[1]);
}
