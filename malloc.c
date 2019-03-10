#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int cnt;
/////////////////////////////////////////////////////////////////////
char *input(char (*p)[20])
{
cnt++;
getchar();
p=realloc(p,cnt*20);
puts("enter name: ");
gets(p[cnt-1]);
return p;
}
/////////////////////////////////////////////////////////////////////
void print(char (*p)[20])
{
int i;
for(i=0;i<cnt;i++)
printf("name[%d]= %s\n",i,p[i]);
}
////////////////////////////////////////////////////////////////////
void search(char (*p)[20])
{
int i;
char s1[20];
printf("enter the name to search: ");
getchar();
gets(s1);
for(i=0;i<cnt;i++)
if(strcmp(p[i],s1)==0)
break;
if(i==cnt)
printf("not found");
else
printf("found at location:p[%d]",i);
}
/////////////////////////////////////////////////////////////////////
void delete(char (*p)[20])
{
int i;
char s1[20];
printf("enter the name to delete: ");
getchar();
gets(s1);
for(i=0;i<cnt;i++)
if(strcmp(p[i],s1)==0)
break;
if(i==cnt)
printf("not found");
else
memmove(p+i,p+i+1,(cnt-i-1)*20);
cnt--;
}
/////////////////////////////////////////////////////////////////////
void update(char (*p)[20])
{
int i;
char s1[20],s2[20];
printf("enter the name to update: ");
getchar();
gets(s1);
printf("enter the updated name: ");
getchar();
gets(s2);
for(i=0;i<cnt;i++)
if(strcmp(p[i],s1)==0)
break;
if(i==cnt)
printf("not found");
else
strncpy(p+i,s2,strlen(s2)+1);
}
/////////////////////////////////////////////////////////////////////
main()
{
char ch;
char (*p)[20]=0;
printf("*****menu option*****\n");
while(1)
{
printf("i:input\np:print\nd:delete\ns:search\nu:update\nq:quit\n");
printf("enter your option: ");
scanf("%c",&ch);
switch(ch)
{
	case 'i':
		p=input(p);
		break;
	case  'p':
		print(p);

		break;
	case 'd':
		delete(p);
		break;
	case 's':
		search(p);
		break;
	case 'u':
		update(p);
		break;
	case 'q':
		return;
	default:
		printf("invalid option");
		
}
}
}
