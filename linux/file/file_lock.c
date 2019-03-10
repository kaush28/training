#include"headers.h"
main()
{
//system("clear");
struct flock v;
int fd,size,i;
char *buf="abcdefghijklmnopqrstuvwxyz";
fd=open("datafile",O_RDWR|O_APPEND);
////////////////////////////////////////////////
printf("about towrite in the file.\n");
//////////////////write lock applied/////////////////////////
/*
v.l_type=F_WRLCK;
v.l_whence=0;
v.l_start=0;
v.l_len=0;
fcntl(fd,F_SETLKW,&v);
*/
/////////////writing data in file///////////////////////////////////
printf("writing in datafile through %d\n",getpid());
for(i=0;buf[i];i++)
{
write(fd,buf+i,1);
sleep(1);
printf("%c",buf[i]);
system("clear");
fflush(stdout);
}
//////////////////////unlocking the file/////////////////////////
/*
v.l_type=F_UNLCK;
fcntl(fd,F_SETLK,&v);
*/
///////////////////////////////////////////////
}
