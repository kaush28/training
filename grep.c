#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int n,char **p)
{
FILE *fp;
char buf[100];
int i,cnt=0;
fp=fopen(p[1],"r");
if(fp==0)
{
printf("error:can't open the file.");
return;
}
while(fgets(buf,100,fp))
{
cnt++;
if(strstr(buf,p[2]))
printf("line %d:%s",cnt,buf);
}
fclose(fp);
}
