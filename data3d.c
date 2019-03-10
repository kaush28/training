#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<termios.h>
int cnt;
char (*s)[2][20]=0;
///////////////////////////////////////////////////////////////////
void input(void)
{
int i;
cnt++;
s=realloc(s,cnt*40);
puts("\nenter name and contact no: ");
for(i=0;i<2;i++)
{
getchar();
gets(s[cnt-1][i]);
}
}
///////////////////////////////////////////////////////////////////
void print(void)
{
int i,j;
for(i=0;i<cnt;i++)
{
printf("\ndata[%d]:",i);
printf("name:%s	contact no: %s",s[i][0],s[i][1]);
printf("\n");
}
}
///////////////////////////////////////////////////////////////////
void search(void)
{
int i;
char s1[20];
puts("enter the name to search: ");
gets(s1);
for(i=0;i<cnt;i++)
{
if(strcmp(s[i][0],s1)==0)
break;
}
if(i==cnt)
printf("not found");
else
printf("\nfound at:s[%d]::%s:%s\n",i,s[i][0],s[i][1]);
}
///////////////////////////////////////////////////////////////////
void delete(void)
{
int i,j;
char s1[20];
printf("\nenter the name to delete: ");
gets(s1);
for(i=0;i<cnt;i++)
{
if(strcmp(s[i][0],s1)==0)
break;
}
if(i==cnt)
printf("not found");
else
{
memmove(s+i,s+i+1,(cnt-i-1)*40);
cnt--;
s=realloc(s,cnt*40);
}
}
///////////////////////////////////////////////////////////////////
void update(void)
{
int i,j;
char s1[2][20];
char s2[20];
printf("\nenter the name to update: ");
gets(s2);
for(i=0;i<cnt;i++)
{
if(strcmp(s[i][0],s2)==0)
break;
}
if(i==cnt)
printf("not found");
else
{
puts("\nenter the updated name and contact no: ");
for(j=0;j<2;j++)
{
gets(s[i][j]);
}
}
}
////////////////////////////////////////////////////////////////////
main()
{
char ch;
struct termios v;
tcgetattr(0,&v);
v.c_lflag&=~ICANON;
tcsetattr(0,TCSANOW,&v);
while(1)
{
printf("*****menu option*****\n");
printf("i:input\np:print\ns:search\nd:delete\nu:update\nq:quit\n");
printf("\nenter your choice: ");
scanf("%c",&ch);
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
	case'u':
		update();
		break;
	case 'q':
		return;
	default:
		printf("invalid option\n");
}
}
}
