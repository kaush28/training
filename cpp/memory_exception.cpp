#include<iostream>
using namespace std;
main()
{
int x,*ptr=NULL;
cout<<"enter the value of x:";
cin>>x;
try
{
if(x==1)
ptr=new int[5];
if(!ptr)
throw "";
}
catch(...)
{
cout<<"memory not allocated:"<<endl;
}
}
