#include"headers.h"
main(int n,char **s)
{
int p[2];
pipe(p);
if(fork())
{//parent process
close(1);
dup(p[1]);
execlp("nm","nm",s[1],NULL);
}
else
{//child process
close(0);
dup(p[0]);
execlp("grep","grep",s[2],NULL);
}
}
