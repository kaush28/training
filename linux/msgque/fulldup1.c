#include"headers.h"
struct msgbuf
{
long mtype;
char mtext[20];
};
main(int n,char **p)
{
struct msgbuf v;
int id;
if(fork())
{
id=msgget(3,IPC_CREAT|0600);
while(1)
{
v.mtype=atoi(p[1]);
bzero(v.mtext,20);
if(msgrcv(id,&v,20,v.mtype,0)==-1)
{
perror("msgrcv");
exit(0);
}
printf("%s\n",v.mtext);
}
}
else
{
id=msgget(3,IPC_CREAT|0600);
while(1)
{
v.mtype=atoi(p[2]);
printf("enter msg:\n");
gets(v.mtext);
if(msgsnd(id,&v,strlen(v.mtext)+1,0)==-1)
{
perror("msgsnd");
exit(0);
}
}
}
}
