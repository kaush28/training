#include"headers.h"
void f1(int n)
{
printf("in f1..\n");
//alarm(2);
sleep(5);
printf("exiting...\n");
}
main()
{
struct sigaction v1,v2;
printf("%d.....%d..\n",getpid(),getppid());
v1.sa_handler=f1;
//sigaction(SIGALRM,&v1,NULL);
//v1.sa_flags=SA_RESETHAND;
v1.sa_flags=0;
sigfillset(&v1.sa_mask);
//sigemptyset(&v1.sa_mask);
sigaction(SIGINT,&v1,NULL);
/*
if(v2.sa_handler==SIG_DFL)
printf("previous process=default.\n");
else if(v2.sa_handler==SIG_IGN)
printf("previous process=ignore.\n");
else
printf("previous process=user defined.\n");
*/
if(v1.sa_handler==SIG_DFL)
printf("current process=default.\n");
else if(v1.sa_handler==SIG_IGN)
printf("current process=ignore.\n");
else
printf("current process=user defined.\n");
//alarm(2);
while(1);
}
