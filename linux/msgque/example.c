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
id=msgget(1,IPC_CREAT|0600);
if(id==-1)
{
perror("msgget");
exit(0);
}
v.mtype=atoi(p[1]);
while(1)
{
printf("waiting: \n");
if(msgrcv(id,&v,20,v.mtype,0)==-1)
{
perror("msgrcv");
exit(0);
}
printf("%d: %s\n",getpid(),v.mtext);
if(strcmp(v.mtext,"quit")==0)
break;
}
}
