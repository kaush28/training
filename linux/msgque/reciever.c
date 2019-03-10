////////////////server//////////////////
#include"headers.h"
struct msgbuf
{
long mtype;
int mdata[3];
char mtext[20];
};
main(int n,char **p)
{
while(1)
{
struct msgbuf v;
char c;
int id,no=0,ch=0,sp=0,i;
id=msgget(3,IPC_CREAT|0600);
v.mtype=atoi(p[1]);
if(msgrcv(id,&v,sizeof(v),v.mtype,0)==-1)
{
perror("msgrcv");
exit(0);
}
printf("data received:\n ");
printf("%s\n",v.mtext);
i=0;
while(v.mtext[i])
{
c=v.mtext[i];
if((c>=48)&&(c<=57))
//if(isdigit(v.mtext[i]))
no++;
else if((c>=97)&&(c<=123))
ch++;
else
sp++;
i++;
}
v.mdata[0]=no;
v.mdata[1]=ch;
v.mdata[2]=sp;
v.mtype=atoi(p[2]);
if(msgsnd(id,&v,sizeof(v),0)==-1)
{
perror("msgsnd");
exit(0);
}
printf("data send.\n");
}
}
