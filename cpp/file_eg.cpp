#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
main()
{
char ch[50];
ofstream out("data");
out<<"welcome to vector:"<<endl;;
out<<"embedded training institute:"<<endl;
out<<"hyderabad"<<endl;
out.close();
ifstream in("data");
while(in)
{
//std::string ch;
//in>>ch;

in.getline(ch,20);
cout<<ch<<endl;
}
in.close();
}
