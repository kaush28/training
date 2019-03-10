#include<stdio.h>
#include<unistd.h>
main()
{
char *ptr="ps";
char *ap[]={"-e","-t",NULL};
printf("%d.....%d\n",getpid(),getppid());
//execlp("ls","ls","-l",NULL);
//execlp("ps","ps","-e",NULL);
execv("/bin/ps",ap);
printf("exitng..%d\n",getpid());
}
