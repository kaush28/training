#include"headers.h"
int fd;
pthread_t tid1,tid2;
void *f1(void *p)
{
fd=open("a1",O_RDONLY);
}
void *f2(void *p)
{
char buf[50];
sleep(2);
read(fd,buf,50);
printf("%s\n",buf);
}
main()
{
pthread_create(&tid1,NULL,f1,NULL);
pthread_create(&tid2,NULL,f2,NULL);
pthread_exit(0);
}
