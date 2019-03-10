#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cnt;
char **sort(char *p,char (*s)[20])
{
FILE *fp;
int i=0,j;
char buf[20];
fp=fopen(p,"r");
while(fgets(buf,20,fp))
{
cnt++;
}
s=realloc(s,cnt*20);
rewind(fp);
for(i=0;i<cnt;i++)
fgets(s[i],20,fp);
for(i=0;i<cnt;i++)
printf("%s",s[i]);
for(i=0;i<cnt;i++)
{
for(j=i+1;j<cnt;j++)
{
if(strcmp(s[i],s[j])>0)
{
strcpy(buf,s[i]);
strcpy(s[i],s[j]);
strcpy(s[j],buf);
}
}
}
fclose(fp);
return s;
}
main(int n,char **p)
{
FILE *fp;
char (*buf)[20]=NULL;
int i;
fp=fopen(p[1],"r");
if(fp==0)
{
printf("error:can't open the file.");
return;
}
buf=sort(p[1],buf);
fp=fopen(p[1],"w");
for(i=0;i<cnt;i++)
{
fputs(buf[i],fp);
}
fclose(fp);
}
