#include"headers.h"
main(int n,char **p)
{
char ch;
int fd1,fd2,ret,i;
fd1=open(p[1],O_RDONLY);
close(0);
dup(fd1);
fd2=open(p[2],O_WRONLY|O_CREAT|O_TRUNC,0600);
close(1);
dup(fd2);
while((scanf("%c",&ch))==1)
printf("%c",ch);
}
