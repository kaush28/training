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
printf("error:file can't open.");
while((ch=fgetc(fp))!=EOF)
{
cnt++;
}
fclose(fp);
return cnt;
}
void copy(char *p,char *buf)
{
FILE *fp;
char ch;
char *s;
int i;
fp=fopen(p,"r");
if(fp==0)
printf("error:can't open the file");
i=0;
while((ch=fgetc(fp))!=EOF)
{
buf[i]=ch;
i++;
}
fclose(fp);
}
void hide(char *p1,char *p2)
{
char *s;
s=p1;
while(s=strstr(s,p2))
{
memset(s,'*',strlen(p2));
s++;
}
}
main(int n,char **p)
{
FILE *fp;
char *buf;
char ch;
int i,cnt=0;
fp=fopen(p[1],"r");
if(fp==0)
printf("error:can't open the file.");
cnt=size(p[1]);
buf=calloc(1,cnt+1);
copy(p[1],buf);
hide(buf,p[2]);
fp=fopen(p[1],"w");
for(i=0;buf[i];i++)
{
ch=buf[i];
fputc(ch,fp);
}
fclose(fp);
}
