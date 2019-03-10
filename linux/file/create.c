#include"headers.h"
#include<fcntl.h>
main(int n,char **p)
{
int fd1,fd2;
char *buf;
int ret;
//char ch;
fd1=open(p[1],O_RDWR);
ret=lseek(fd1,0,2);
lseek(fd1,0,0);
buf=malloc(ret+1);
read(fd1,buf,ret);
//puts(buf);
//fd=creat(p[1],O_RDWR);
//write(fd,"xyzasdfgh",6);
close(fd1);
fd2=open(p[2],O_WRONLY|O_CREAT|O_TRUNC,S_IRUSR|S_IWUSR);
//fd2=open(p[2],O_WRONLY|O_CREAT);
write(fd2,buf,ret);
close(fd2);
}
