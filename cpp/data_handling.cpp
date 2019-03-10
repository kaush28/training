#include<iostream>
using namespace std;
void display(int x)
{
if(x==1)
throw 'a';
else if(x==2)
throw 1234;
else if(x==3)
throw 23.4;
//else
//throw "";
}
main()
{
int x;
cout<<"enter the value of x:";
cin>>x;
try
{
display(x);
}
catch(char x)
{
cout<<"data got:"<<x<<endl;
}
catch(int x)
{
cout<<"data got:"<<x<<endl;
}
catch(double x)
{
cout<<"data got:"<<x<<endl;
}
catch(...)
{
cout<<"exception occured:"<<endl;
}
}
