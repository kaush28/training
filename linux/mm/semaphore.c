#include"headers.h"
#include<sys/ipc.h>
#include<sys/sem.h>
main()
{
struct sembuf v;
int i,id,fd;
id=semget(1,2,IPC_CREAT|0666);
fd=open("f1",O_RDWR|O_CREAT|O_APPEND,0600);
semctl(id,0,SETVAL,0);
semctl(id,1,SETVAL,1);
if(fork()==0)
{int i=0;
char ch;
v.sem_num=0;
v.sem_op=0;
v.sem_flg=0;
char buf[7]="abcdef";
semop(id,&v,1);
semctl(id,0,SETVAL,1);
while(buf[i])
{
//semop(id,&v,1);
//semctl(id,0,SETVAL,1);
write(fd,&buf[i],1);
i++;
//semctl(id,1,SETVAL,0);
}
semctl(id,1,SETVAL,0);
}
else
{
 int i=0;
char ch;
v.sem_num=1;
v.sem_op=0;
v.sem_flg=0;
char buf[7]="123456";
semop(id,&v,1);
semctl(id,1,SETVAL,1);
while(buf[i])
{
//semop(id,&v,1);
//semctl(id,1,SETVAL,1);
write(fd,&buf[i],1);
i++;
//semctl(id,0,SETVAL,0);
}
semctl(id,0,SETVAL,0);
}
}
