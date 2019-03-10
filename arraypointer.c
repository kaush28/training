#include<stdio.h>
int cnt; 
main()
{
char **p;
int i;
cnt++;
*p=realloc(*p,cnt*sizeof(char*));
p[cnt-1]
}
