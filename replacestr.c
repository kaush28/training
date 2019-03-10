#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size(char *p)
{
FILE *fp;
char ch;
int cnt=0;
fp=fopen(p,"r");
if(fp==0)
{
printf("error:can't open the file.");
return;
}
while((ch=fgetc(fp))!=EOF)
{
cnt++;
}
fclose(fp);
return cnt;
}
void copy(char *p1,char *p2)
{
FILE *fp;
char ch;
int i=0;
fp=fopen(p1,"r");
while((ch=fgetc(fp))!=EOF)
{
p2[i]=ch;
i++;
}
fclose(fp);
}
char *replace(char *p1,char *p2,char *p3)
{
int size,l1,l2,cnt=0;
size=strlen(p1)+1;
l1=strlen(p2);
l2=strlen(p3);
char *str;
str=p1;
while(str=strstr(str,p2))
{
cnt++;
str++;
}
if(l2>l1)
size+=cnt*(l2-l1);
p1=realloc(p1,size);
str=p1;
while(str=strstr(str,p2))
{
memmove(str+l2,str+l1,strlen(str+l1)+1);
memcpy(str,p3,l2);
str++;
}
return p1;
}
main(int n,char **p)
{
FILE *fp;
char ch;
char *buf;
int i,cnt;
fp=fopen(p[1],"r");
if(fp==0)
printf("error:can't open the file.");
cnt=size(p[1]);
buf=calloc(1,cnt+1);
copy(p[1],buf);
buf=replace(buf,p[2],p[3]);
fp=fopen(p[1],"w");
for(i=0;buf[i];i++)
{
ch=buf[i];
fputc(ch,fp);
}
fclose(fp);
}
