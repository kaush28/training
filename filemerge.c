#include<stdio.h>
#include<stdlib.h>
main(int n,char **p)
{
FILE *f1,*f2,*f3;
char *buf1=NULL,*buf2=NULL;
int size;
f1=fopen(p[1],"a");
if(f1==0)
printf("error:can't open the file.");
f2=fopen(p[2],"r");
if(f2==0)
printf("error:can't open the file 2");
fseek(f2,0,2);
size=ftell(f2)+1;
rewind(f2);
buf1=calloc(1,size);
fread(buf1,size-1,1,f2);
fwrite(buf1,size,1,f1);
fclose(f2);
free(buf1);
f3=fopen(p[3],"r");
if(f3==0)
printf("error:can't open the file 3.");
fseek(f3,0,2);
size=ftell(f3)+1;
rewind(f3);
buf2=calloc(1,size);
fread(buf2,size-1,1,f3);
fwrite(buf2,size,1,f1);
fclose(f1);
fclose(f3);
}
