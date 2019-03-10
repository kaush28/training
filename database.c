#include<stdio.h>
#include<string.h>
static int cnt;
///////////////////////////////////////////////////////////////
void input(char (*s)[20])
{
int i;
i=cnt;
char option;
for(i=cnt;;i++)
{
printf("location:%d : ",i);
scanf("%s",s[i]);
cnt++;
printf("hit c for continue or s for stop\n");
scanf(" %c",&option);
if(option=='c')
continue;
else
break;
if(cnt<10)
continue;
else
printf("memory full");
}
}
///////////////////////////////////////////////////////////////////
void delete(char (*s)[20])
{
int i;
char option;
char s1[20];
int *p;
printf("hit m for removing from location or d for data:");
scanf(" %c",&option);
if(option=='m')
{
printf("enter the location to delete: ");
scanf("%d",&i);
if(i<=cnt)
{
memmove(s+i,s+i+1,(cnt-i-1)*20);
cnt--;
}
else
printf("provided memory empty");
}
/*
else if(option=='d')
{
printf("enter the data to delete: ");
gets(s1);
p=strstr(s,s1);
memmove(s+p,s+p+1,(cnt-p-1)*20);
cnt--;
}
*/
else
printf("invalid option");
}
///////////////////////////////////////////////////////////////////
void print(char (*s)[20])
{
int i;
for(i=0;i<cnt;i++)
{
printf("location:%d :%s\n",i,*(s+i));
}
}
///////////////////////////////////////////////////////////////////
void search(char (*s)[20])
{
int i;
char *p;
char s1[20];
printf("\nenter the data to search:");
scanf("%s",s1);
for(i=0;i<cnt;i++)
{
p=strstr(s[i],s1);
if(p)
break;
}
if(i==cnt)
printf("\nnot found\n");
else
printf("\nfound at location: s[%d]\n",i);
}
////////////////////////////////////////////////////////////////
void arrange(char (*s)[20])
{
int i,j;
char s1[20];
for(i=0;i<cnt;i++)
{
for(j=i+1;j<cnt;j++)
{
if(strcmp(s[i],s[j])>0)
{
strcpy(s1,s[i]);
strcpy(s[i],s[j]);
strcpy(s[j],s1);
}
}
}
}
////////////////////////////////////////////////////////////////
void modify(char (*s)[20])
{
int i;
printf("enter the location to modify: ");
scanf("%d",&i);
printf("enter the modified data: ");
scanf("%s",s+i);

}
////////////////////////////////////////////////////////////////
main()
{
char ch;
char s[10][20];
printf("*****student database*****\n");
START:
printf("i:input\nr:remove\np:print\ns:search\na:arrange\nm:modify\nq:quit\n");
printf("enter the option: ");
scanf(" %c",&ch);
if(ch=='i')
input(s);
else if(ch=='r')
delete(s);
else if(ch=='p')
print(s);
else if(ch=='s')
search(s);
else if(ch=='a')
arrange(s);
else if(ch=='m')
modify(s);
else if(ch=='q')
return;
else
printf("invalid option\n");
goto START;
}
