#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
main()
{
char ch[50];
fstream file;
file.open("datafile",ios::out);
file<<"welcome to vector:"<<endl;
file<<"embedded training institute:"<<endl;
file<<"hyderabad:"<<endl;
file.close();
file.open("datafile",ios::in);
while(file)
{
file.getline(ch,50);
cout<<ch<<endl;
}
file.close();
}
