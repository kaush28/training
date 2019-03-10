#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
main(int n,char **p)
{
int len,size=0,l=0;
int nline=0;
char **str=NULL;
char ch[81];
fstream file;
file.open(p[1],ios::in|ios::out);
//file.seekg(0,ios::end);
//len=file.tellg();
//file.seekg(0,ios::beg);
//cout<<len<<endl;
nline=1;
while(file)
{
file.getline(ch,80);
if(len=(strlen(ch)+1)>5)
{
nline++;
}
}
file.clear();
cout<<nline<<endl;
/*file.open(p[1],ios::out);
for(l=0;str[l];l++)
{
cout<<str[l]<<endl;
file<<str[l];
}*/
file.close();
}
