#include<stdio.h>
int size(char *p[1])
{
char ch;
FILE *f1;
int cnt=0,no=0;
f1=fopen(p[1],"r");
if(f1==0)
{
printf("can't open the file.\n");
return;
}
while(ch!=EOF)
{
cnt++;
ch=fgetc(f1);
if(ch=='\n')
no++;
}
fclose(f1);
printf("character=%d,line=%d",cnt,no);
return cnt;
}
main(int n,char **p)
{
FILE *f1;
char ch;
int cnt,no;
f1=fopen(p[1],"r");
if(f1==0)
{
printf("cant opent the file.");
return;
}
cnt=size(p[1]);
fclose(f1);
}
