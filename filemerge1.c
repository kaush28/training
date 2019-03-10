#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main(int y,char **p)
{
FILE *f1,*f2;
int n,size1,size2;
char *buf1=NULL,*buf2=NULL;
char ch;
f1=fopen(p[1],"r");
if(f1==0)
{
printf("error:can't open the file1.");
return;
}
fseek(f1,0,2);
size1=ftell(f1)+1;
rewind(f1);
buf1=calloc(1,size1);
fread(buf1,size1-1,1,f1);
fclose(f1);
f2=fopen(p[2],"r");
if(f2==0)
{
printf("error:can't open the file2.");
return;
}
fseek(f2,0,2);
size2=ftell(f2)+1;
rewind(f2);
buf2=calloc(1,size2);
fread(buf2,size2-1,1,f2);
fclose(f2);
n=atoi(p[3]);
//printf("%d",&n);
buf1=realloc(buf1,size1+size2);
memmove(buf1+n+size2-1,buf1+n,strlen(buf1+n+1));
memcpy(buf1+n,buf2,size2-1);
printf("%s",buf1);
f1=fopen(p[1],"w");
fwrite(buf1,size1+size2-1,1,f1);
fclose(f1);
}
