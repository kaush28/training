//////////////////client////////////////////
#include"headers.h"
struct msgbuf
{
long mtype;
int mdata[3];
char mtext[20];
};
main(int n,char **p)
{
struct msgbuf v;
int id;
id=msgget(3,IPC_CREAT|0600);
v.mtype=atoi(p[1]);
printf("enter string:\n");
gets(v.mtext);
if(msgsnd(id,&v,sizeof(v),0)==-1)
{
perror("msgsnd");
exit(0);
}
v.mtype=atoi(p[2]);
if(msgrcv(id,&v,sizeof(v),v.mtype,0)==-1)
{
perror("msgrcv");
exit(0);
}
printf("number=%d\ncharacter=%d\nspecial=%d\n",v.mdata[0],v.mdata[1],v.mdata[2]);
}
