#include"headers.h"
main(int n,char **p)
{
struct sockaddr_in saddr;

///////////////////////////////////
if(n<2)
{
printf("invalid number of arguments.\n");
return;
}
//////////////////////////////////

int sfd;

sfd=socket(PF_INET,SOCK_STREAM,0);
if(sfd<0)
{
perror("socket");
exit(0);
}
//////////////////////////////////

printf("bind.....\n");
saddr.sin_port=htons(atoi(p[1]));
saddr.sin_family=AF_INET;
saddr.sin_addr.sin_addr=inet_addr("0.0.0.0");

if(bind(sfd,(const struct sockaddr *)&saddr,sizeof(saddr)<0))
{
perror("bind\n");
exit(0);
}
printf("bind successfull\n");
//////////////////////////////////

printf("creating connection queue.....\n");
if(listen(sfd,1)<0)
{
perror("listen");
exit(0);
}
printf("listen successfull\n");
/////////////////////////////////////

char buf[100];
struct sockaddr_in caddr;
int cfd,clen=sizeof(caddr);

printf("waiting to accept connection from client.....\n");

cfd=accept(sfd,(struct sockaddr *)&caddr,&clen);

if(cfd<0)
{
perror("accept");
exit(0);
}
printf("client accepted successfully\n");

////////////////////////////////////////
client_info(caddr,cfd);

while(1)
{
printf("waiting for message from client..\n");
ret=recv(cfd,buf,100,0);
if(ret<0)
{
perror("recv");
exit(0);
}

else if(ret==0)
{
printf("client with: \n");
client_info(caddr,cfd);
printf("terminated abruptly.\n");
exit(0);
}

else
{
printf("recieved: %s\n"buf);
}
}
}
