#include<stdio.h>
#include<string.h>
struct date
{
unsigned int day:5;
unsigned int month:4;
unsigned int year:15;
}dob;
struct record
{
char name[20];
float marks;
union identity
{
char pan[10];
char dl[20];
char vector[20];
}id;
char contact[20];
struct date dob;
}v;
int cnt=0;
//////////////////////////////////////////////////////////////////
struct record *input(struct record *t)
{
int a,b,c,d;
cnt++;
t=realloc(t,cnt*sizeof(v));
getchar();
printf("enter name: ");
gets((t+cnt-1)->name);
printf("enter contact no: ");
gets((t+cnt-1)->contact);
/////////////////////////////////////
printf("enter id: ");
printf("\n1:pan\n2:dl\n3:vector\n:");
scanf("%d",&a);
if(a==1)
scanf(&(t+cnt-1)->id.pan);
else if(a==2)
scanf("%s",&(t+cnt-1)->id.dl);
else if(a==3)
scanf("%s",&(t+cnt-1)->id.vector);
else
printf("invalid option\n");
///////////////////////////////////////
printf("enter marks: ");
scanf("%f",&(t+cnt-1)->marks);
printf("enter date_of_birth: ");
scanf("%d %d %d",&b,&c,&d);
t[cnt-1].dob.day=b;
t[cnt-1].dob.month=c;
t[cnt-1].dob.year=d;
return t;
}
///////////////////////////////////////////////////////////////////
void print(struct record *t)
{
int i;
for(i=0;i<cnt;i++)
{
printf("student[%d]: %s %4d %4f %4s %d/%d/%d\n",i,t[i].name,t[i].id,t[i].marks,t[i].contact,t[i].dob.day,t[i].dob.month,t[i].dob.year);
}
}
///////////////////////////////////////////////////////////////////
void search(struct record *t)
{
int i;
char p[20];
getchar();
printf("enter the name to search: ");
gets(p);
for(i=0;i<cnt;i++)
{
if(strcmp((t+i)->name,p)==0)
printf("found student[%d]: %s %4d %4f %4s",i,t[i].name,t[i].id,t[i].marks,t[i].contact);
}
}
///////////////////////////////////////////////////////////////////
void delete(struct record *t)
{
int i;
char p[20];
getchar();
printf("enter the name to delete: ");
gets(p);
for(i=0;i<cnt;i++)
{
if(strcmp((t+i)->name,p)==0)
{
memmove(t+i,t+i+1,(cnt-i-1)*sizeof(t[0]));
cnt--;
realloc(t,cnt*sizeof(v));
}
}
}
///////////////////////////////////////////////////////////////////
void update(struct record *t)
{
int i,a;
char p[20];
printf("enter the name to update: ");
getchar();
gets(p);
for(i=0;i<cnt;i++)
{
if(strcmp((t+i)->name,p)==0)
{
printf("enter the current information: ");
printf("\nenter the name: ");
gets((t+i)->name);
printf("enter the contact no: ");
gets((t+i)->contact);
printf("enter the roll no: ");
scanf("%d",&a);
//t[i].roll=a;
printf("enter the marks: ");
scanf("%f",&(t+i)->marks);
}
}
}
//////////////////////////////////////////////////////////////////
main()
{
struct record *st=NULL;
char ch;
while(1)
{
printf("\n*****menu option*****\n");
printf("i:input\np:print\ns:search\nd:delete\nu:update\nq:quit\n");
scanf(" %c",&ch);
switch(ch)
{
case 'i':
	st=input(st);
break;
case 'p':
	print(st);
break;
case 's':
	search(st);
break;
case 'd':
	delete(st);
break;
case 'u':
	update(st);
break;
case 'q':
return;
default:
printf("invalid option");
}
}
}
