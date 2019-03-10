#include"headers.h"
void f1(int n)
{
printf("in f1\n");
}
main()
{
void (*p)(int);
signal(18,SIG_IGN);
p=signal(18,SIG_IGN);
signal(18,p);
if(p==SIG_DFL)
printf("DEFAULT SIGNAL.\n");
else if(p==SIG_IGN)
printf("signal ignored.\n");
else
printf("user-defined signal.\n");
}
