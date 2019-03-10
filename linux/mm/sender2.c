#include"headers.h"
pthread_t tid1,tid2;
struct msgbuf
{
long mtype;
char mtext[20];
}v1,v2;
int id;
void *f1(void *p)
{
while(1)
{
v2.mtype=2;
gets(v2.mtext);
if(msgsnd(id,&v2,strlen(v2.mtext)+1,0)==-1)
{
perror("msgsnd");
exit(0);
}
}
}
void *f2(void *p)
{
while(1)
{
v1.mtype=1;
if(msgrcv(id,&v1,20,v1.mtype,0)==-1)
{
perror("msgsnd");
exit(0);
}
puts(v1.mtext);
}
}
main()
{
id=msgget(1,IPC_CREAT|0600);
if(id==-1)
{
perror("msgget");
exit(0);
}
pthread_create(&tid1,NULL,f1,NULL);
pthread_create(&tid2,NULL,f2,NULL);
pthread_exit(0);
}
