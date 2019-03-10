#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int n,char **p)
{
FILE *fp;
char linebuf[100];
char commentline[100];
char *buf=NULL;
char *ptr;
int i,cnt=0,size;
char ch;
fp=fopen(p[1],"r");
if(fp==0)
{
printf("eror:can't open the file.");
return;
}
fseek(fp,0,2);
size=ftell(fp)+1;
rewind(fp);
buf=calloc(1,size);
while(fgets(linebuf,100,fp))
{
if(ptr=strstr(linebuf,"//"))
{
linebuf[ptr-linebuf]='\0';
for(i=0;linebuf[i];i++)
{
buf[cnt]=linebuf[i];
cnt++;
if(linebuf[i+1]=='\0')
{
buf[cnt]='\n';
cnt++;
}
}
}
else if(ptr=strstr(linebuf,"/*"))
{
linebuf[ptr-linebuf]='\0';
for(i=0;linebuf[i];i++)
{
buf[cnt]=linebuf[i];
cnt++;
}
if(ptr=strstr(linebuf,"*/"));
else
{
while(fgets(linebuf,100,fp))
{
if(ptr=strstr(linebuf,"*/"))
break;
}
}
/*
memmove(linebuf,ptr+2,strlen(ptr+2));
for(i=0;linebuf[i];i++)
{
buf[cnt]=linebuf[i];
cnt++;
}
*/
buf[cnt]='\n';
cnt++;
}
else
{
for(i=0;linebuf[i];i++)
{
buf[cnt]=linebuf[i];
cnt++;
}
}
}
printf("%s",buf);
fp=fopen(p[1],"w");
fwrite(buf,cnt,1,fp);
fclose(fp);
}
