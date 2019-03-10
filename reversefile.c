#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int n,char **p)
{
FILE *f1,*f2;
int i,j,size;
int k=0;
char *buf1,*buf2;
char linebuf[100];
f1=fopen(p[1],"r");
fseek(f1,0,2);
size=ftell(f1)+1;
rewind(f1);
buf1=calloc(1,size);
fread(buf1,size-1,1,f1);
fclose(f1);
printf("%s",buf1);
buf2=calloc(1,size);
for(i=size-1;i>=0;i--)
{
if((buf1[i]==' ')||(i==0))
{
if(i==0) i=-1;
for(j=i+1;((buf1[j]!=' ')&&(buf1[j]!='\0'));j++)
{
if(buf1[j]=='\n')
{
buf2[k]=' ';
k++;
break;
}
buf2[k]=buf1[j];
k++;
printf("%s\n",buf1);
if((buf1[j+1]==' ')||(buf1[j+1]=='\0'))
{
if(buf1[j+1]=='\0')
{
buf2[k]=' ';
k++;
}
else
{
buf2[k]=' ';
k++;
}
}
}
}
}
printf("%s",buf2);
f2=fopen(p[2],"w");
fwrite(buf2,size,1,f2);
fclose(f2);
}
