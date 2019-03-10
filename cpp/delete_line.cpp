#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
main(int n,char **p)
{
int len,size=0,l=0,i;
char **str=NULL;
char ch[80];
fstream file;
file.open(p[1],ios::in);
//file.seekg(0,ios::end);
//len=file.tellg();
//file.seekg(0,ios::beg);
//cout<<len<<endl;
while(file)
{
file.getline(ch,80);
if(len=(strlen(ch)+1)>5)
{
l++;
str=(char **)realloc(str,l*sizeof(char *));
str[l-1]=(char *)realloc(str[l-1],len);
strcpy(str[l-1],ch);
}
}
file.close();
file.open(p[1],ios::out);
for(i=0;i<l;i++)
{
cout<<str[i]<<endl;
file<<str[i]<<endl;
}
file.close();
}
