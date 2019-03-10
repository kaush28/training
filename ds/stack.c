#include<stdio.h>
#include<stdlib.h>
#define max 5
int cnt=0;
struct student
{
char name[20];
int roll;
struct student *next;
};
void push(struct student **top)
{
struct student *nu;
nu=malloc(sizeof(struct student));
getchar();
printf("enter the name of student: ");
gets(nu->name);
printf("enter the roll no: ");
scanf("%d",&nu->roll);
nu->next=*top;
*top=nu;
cnt++;
}
void pop(struct student **top)
{
struct student *temp;
temp=*top;
*top=(*top)->next;
free(temp);
temp=NULL;
cnt--;
}
void print(struct student *top)
{
if(cnt==0)
printf("nothing to display.\n");
struct student *temp;
temp=top;
while(temp)
{
printf("%s----%d\n",temp->name,temp->roll);
temp=temp->next;
printf("\n");
}
}
int isempty(void)
{
if(cnt==0)
return 1;
else
return 0;
}
int isfull(void)
{
if(cnt==5)
return 1;
else
return 0;
}
main()
{
char ch;
struct student *top=NULL;
while(1)
{
printf("*****menu*****\n");
printf("i:push\np:print\nd:pop\nq:quit\n");
printf("enter ur option: ");
scanf(" %c",&ch);
switch(ch)
{
case 'i':
	if(isfull())
	printf("stack overflow.\n");
	else
	push(&top);
	break;
case 'd':
	if(isempty())
	printf("stack underflow.\n");
	else
	pop(&top);
	break;
case 'p':
	print(top);
	break;
case 'q':
	return;
}
}
}
