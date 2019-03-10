#include<stdio.h>
main(int n,char **p)
{
FILE *f1,*f2;
char ch;
if(n!=3)
{
printf("invalid no. of arguments.");
return;
}
f1=fopen(p[1],"r");
if(f1==0)
{
printf("error in opening the source file.");
return;
}
f2=fopen(p[2],"r");
if(f2==0);
else
printf("target file already existing.\npress y to override or n to exit.");
scanf("%c",&ch);
if(ch=='n')
return;
else if(ch=='y')
{
f2=fopen(p[2],"w");
if(f2==0)
{
printf("target file can't open");
fclose(f2);
}
}
while(1)
{
 ch=fgetc(f1);
if(ch==EOF)
break;
else
fputc(ch,f2);
}
fclose(f1);
fclose(f2);
}
