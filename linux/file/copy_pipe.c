#include"headers.h"
main(int n,char **s)
{
int f1,f2,size;
char *buf;
f1=open(s[1],O_RDONLY);
size=lseek(f1,0,2)+1;
close(f1);
buf=calloc(1,size);
int p[2];
pipe(p);
if(fork())
{//parent process
f1=open(s[1],O_RDONLY);
//close(1);
//dup(p[1];
read(f1,buf,size);
write(p[1],buf,size);
close(f1);
}
else
{//child process
f2=open((s[2]),O_RDWR|O_CREAT|O_TRUNC,0600);
//close(0);
//dup(p[0]);
read(p[0],buf,size);
write(f2,buf,size);
close(f2);
}
}
