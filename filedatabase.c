#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<signal.h>
#include<unistd.h>
struct STUDENT
	{
	char name[20];
	int roll;
	float marks;
	struct STUDENT *next;
	}student;
struct STUDENT *head;
void input(void)
{
struct STUDENT *buf,*last;
buf=malloc(sizeof(student));
getchar();
printf("enter the name: ");
gets((buf->name));
printf("enter the roll: ");
scanf("%d",&(buf->roll));
printf("énter the marks: ");
scanf("%f",&(buf->marks));
	if((head==0)||(buf->roll)<(head->roll))
		{
		buf->next=head;
		head=buf;
//return head;
		}
	else
		{
		while((head->next)&&(head->roll)<(buf->roll))
		{
		if((head->next->roll)<(buf->roll))
		break;
		head=head->next;
		}
	if((head->next)==0)
			{
			buf->next=0;
			head->next=buf;
			}
	else
		{
		buf->next=head->next;
		head->next=buf;
		}
//return head;
}
}
void print(void)
{
	struct STUDENT *temp=head;
	while(temp)
		{
		printf("%s %3d %3f\n",(temp->name),(temp->roll),(temp->marks));
		temp=temp->next;
		}
}
void search(void)
{
struct STUDENT *buf=head;
char find[20];
printf("enter the name to search: ");
getchar();
gets(find);
	while(buf->next)
		{
		if(strcmp((buf->name),find)==0)
		break;
		buf=buf->next;	
		}
	if((buf->next)==0)
		printf("not found");
	else
		printf("%s %d %f\n",(buf->name),(buf->roll),(buf->marks));
}
//struct STUDENT *delete(struct STUDENT *head)
void delete(void)
{
	struct STUDENT *temp=head,*prev=0;
	char del[20];
	printf("enter the name to delete: ");
	getchar();
	gets(del);
	while(temp)
		{
		if(strcmp((temp->name),del)==0)
		break;
		prev=temp;
		temp=temp->next;
		}
	if(temp==0)
		printf("not found");
	else if(prev==0)
		{
		head=temp->next;
		free(temp);
		}
	else
		{
		prev->next=temp->next;
		free(temp);
		}
	//return head;
}
void save(void)
{
FILE *fp;
fp=fopen("student.data","w");
while(head)
	{
	fwrite(head,(sizeof(student)-sizeof(int *)),1,fp);
	head=head->next;
	}
printf("auto file saved.\n");
alarm(10);
fclose(fp);
}
//struct STUDENT *getfiledata(struct STUDENT *head)
void getfiledata(void)
{
FILE *fp;
struct STUDENT v,*buf,*temp;
fp=fopen("student.data","r");
while((fread(&v,(sizeof(student)-sizeof(void *)),1,fp))==1)
	{
	buf=malloc(sizeof(student));
	memcpy(buf,&v,sizeof(v)-sizeof(buf));
	buf->next=0;
	if(head==0)
		{
		head=buf;
		temp=buf;
		}
	else
		{
		temp->next=buf;
		temp=buf;
		}
	}
//return head;
}
void f1(int n)
{
save();
//alarm(10);
}
main()
{
FILE *fp;
struct STUDENT *head=NULL;
char ch;
//head=getfiledata(head);
getfiledata();
alarm(10);
signal(SIGALRM,f1);
	while(1)
	{
	printf("\n*****MENU*****\n");
	printf("i:input\np:print\ns:search\nd:delete\nu:update\n");
	printf("d:delete\nc:save\nq:quit\n");
	printf("enter ur option: ");
	scanf(" %c",&ch);
		switch(ch)
		{
		case 'i':
			input();
			break;
		case 'p':
			print();
			break;
		case 's':
			search();
			break;
		case 'd':
			delete();
			break;
		case 'c':
			save();
			break;
		case 'q':
			return;
		default:
			printf("invalid option");
		}
	}
}

















