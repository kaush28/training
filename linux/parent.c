#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
void f1(int n)
{
	wait(0);
	signal(SIGCHLD,SIG_DFL);
}
main()
{
	int i=0,t,v;
	int pid[4];
	pid[0]=getpid();
	printf("%d.....%d..\n",getpid(),getppid());
	if(pid[1]=fork()==0)
	{
		printf("%d.....%d..\n",getpid(),getppid());
		srand(getpid());
		t=rand()%10+1;
		printf("%d...wainting for %d sec.\n",getpid(),t);
		sleep(t);
		printf("%d exiting....%d\n",getpid(),getppid());
		exit(1);
	}
	else
	{
		if(pid[2]=fork()==0)
		{
			printf("%d.....%d..\n",getpid(),getppid());
			srand(getpid());
			t=rand()%10+1;
			printf("%d..waiting for %d sec.\n",getpid(),t);
			sleep(t);
			printf("%d exiting..%d\n",getpid(),getppid());
			exit(2);
		}
		else
		{
			if(pid[3]=fork()==0)
			{
				printf("%d.....%d..\n",getpid(),getppid());
				srand(getpid());
				t=rand()%10+1;
				printf("%d waiting for %d sec.\n",getpid(),t);
				sleep(t);
				printf("%d exiting..%d\n",getpid(),getppid());
				exit(3);
			}
			else
			{
				signal(SIGCHLD,f1);
				printf("%d.....in parent\n",getpid());
				while(1)
				{
					system("ps");
					sleep(1);
				}
			}
		}
	}
}
