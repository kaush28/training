#include"headers.h"
pthread_mutex_t m1;
pthread_t tid1,tid2;
void *thread1_code(void *p)
{
int i;
printf("%s",p);
char ptr1[30]="abcdefghijklmnopqrstuvwxyz";
pthread_mutex_lock(&m1);
for(i=0;ptr1[i];i++)
{
printf("%c",ptr1[i]);
sleep(1);
fflush(stdout);
}
pthread_mutex_unlock(&m1);
}
void *thread2_code(void *p)
{
int i;
printf("%s",p);
char ptr1[30]="12345678901234567890123456";
//pthread_mutex_lock(&m1);
for(i=0;ptr1[i];i++)
{
printf("%c",ptr1[i]);
sleep(1);
fflush(stdout);
}
//pthread_mutex_unlock(&m1);
}
main()
{
//pthread_t tid1,tid2;
pthread_create(&tid1,NULL,thread1_code,"vector");
pthread_create(&tid2,NULL,thread2_code,"india");
pthread_exit(0);
}
