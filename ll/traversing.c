#include<stdio.h>
#include<stdlib.h>
struct link
{
int data;
struct link *next;
}node;
main()
{
int option;
int val;
struct link *nu,*cur,*head=NULL;
while(1)
{
printf("enter the option: ");
scanf("%d",&option);
switch(option)
{
case 1:
printf("enter data: ");
scanf("%d",&val);
nu=malloc(sizeof(struct link));
if(head==NULL)
{
nu->data=val;
head=nu;
cur=nu;
}
else
{
nu->data=val;
cur->next=nu;
cur=nu;
break;


case 2:cur=head;
	while(cur)
	{
	printf("%d,",cur->data);
	cur=cur->next;
	}
	break;
}
}
}
}
