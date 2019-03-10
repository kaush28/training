#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
void reverse(char *);
main(int n,char **p)
{
int size,l=0,i;
char ch[80];
char **s=NULL;
fstream file;
file.open(p[1],ios::in);
////////////reading data from file/////////////
while(file.getline(ch,80))
{
l++;
size=strlen(ch)+1;
s=(char **)realloc(s,l*sizeof(char *));
s[l-1]=(char *)realloc(s[l-1],size);
strcpy(s[l-1],ch);
}
/////////searchin for the data//////////////////
for(i=0;i<l;i++)
{
if(strstr(s[i],p[2]))
reverse(s[i]);
}
for(i=0;i<l;i++)
{
cout<<s[i]<<endl;
//file<<s[i]<<endl;
}
}
void reverse(char *p)
{
int i,j;
int l;
l=strlen(p)-1;
for(i=0,j=l;i<j;i++,j--)
{
p[i]^=p[j];
p[j]^=p[i];
p[i]^=p[j];
}
}
