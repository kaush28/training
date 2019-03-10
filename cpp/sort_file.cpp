#include<iostream>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
main(int n,char **p)
{
int i,j;
int size,l=0;
char **s=NULL;
char ch[80];
char *temp;
fstream file;
file.open(p[1],ios::in);
////////////////getting the data///////////////////////////
while(file.getline(ch,80))
{
l++;
size=strlen(ch)+1;
s=(char **)realloc(s,l*sizeof(char *));
s[l-1]=(char *)realloc(s[l-1],size);
strcpy(s[l-1],ch);
}
file.close();
////////////////////////sorting//////////////////////
for(i=0;i<l;i++)
{
for(j=i+1;j<l;j++)
{
if(strcmp(s[i],s[j])>0)
{
temp=s[i];
s[i]=s[j];
s[j]=temp;
}
}
}
///////////////////saving the data///////////////////////////////
file.open(p[1],ios::out);
for(i=0;i<l;i++)
{
cout<<s[i]<<endl;
file<<s[i]<<endl;
}
file.close();
}
