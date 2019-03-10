#include<iostream>
using namespace std;
main()
{
int n1,n2;
float d;
cout<<"enter two number to divide:"<<endl;
cin>>n1>>n2;
try
{
if(n2==0)
{
throw n2;
}
else
{
d=n1/n2;
cout<<"division:"<<d<<endl;
}
}
catch(int n2)
{
cout<<"division can't be performed."<<endl<<"try another number than zero."<<endl;
}
}
