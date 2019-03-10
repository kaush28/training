////////////server///////
#include"headers.h"
main()
{
int fd,no,sp,al,n[3],i,ret;
char rd_buf[20],ch;
signal(13,SIG_IGN);
while(1)
{
no=sp=al=i=0;
fd=open("fifo1",O_RDONLY);
bzero(rd_buf,20);
ret=read(fd,rd_buf,20);
if(ret==0)
continue;
printf("%s\n",rd_buf);
if(strcmp(rd_buf,"quit")==0)
{
return;
}
//}
ch=97;
while(ch)
{
ch=rd_buf[i];
if(ch>=48&&ch<=57)
no++;
else if(ch>=97&&ch<=123)
al++;
else
sp++;
i++;
}
close(fd);
fd=open("fifo2",O_WRONLY);
n[0]=no;
n[1]=al;
n[2]=sp;
write(fd,n,12);
close(fd);
}
}

