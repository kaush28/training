#include<stdio.h>
#include<stdlib.h>
#define max 5
int cnt=0;
struct queue
{
	char name[20];
	int roll;
	struct queue *next;
}QUEUE;
struct queue *front,*rear;
int isfull(void)
{
if(cnt==max)
return 0;
else 
return 1;
}
int isempty(void)
{
if(cnt==0)
return 0;
else
return 1;
}
void enque(void)
{
struct queue *nu=NULL;
//nu=malloc(sizeof(QUEUE));
nu=malloc(sizeof(struct queue));
nu->next=NULL;
getchar();
printf("enter the name: ");
gets(nu->name);
printf("enter the roll: ");
scanf("%d",&nu->roll);
if(cnt==0)
{
front=nu;
rear=nu;
}
else
{
rear->next=nu;
rear=nu;
}
cnt++;
}
void deque(void)
{
struct queue *temp;
temp=front;
front=front->next;
free(temp);
temp=NULL;
cnt--;
}
void display(void)
{
int i;
struct queue *temp;
temp=front;
if(cnt==0)
printf("nothing to display.\n");
else
{
for(i=0;i<cnt;i++)
{
printf("name=%s---roll=%d\n",temp->name,temp->roll);
temp=temp->next;
}
}
}
main()
{
int option;
while(1)
{
printf("*****menu*****\n");
printf("1:enque\n2:deque\n3:display\n4:quit\n");
printf("enter ur option: ");
scanf("%d",&option);
switch(option)
{
	case 1:
		if(isfull()==0)
		printf("stack overflow\n");
		else
		enque();
		break;
	case 2:
		if(isempty()==0)
		printf("stack underflow.\n");
		else
		deque();
		break;
	case 3:
		display();
		break;
	case 4:
		return;
	default:
		printf("invalid option\n");
}
}
}
