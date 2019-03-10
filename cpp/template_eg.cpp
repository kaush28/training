#include<iostream>
using namespace std;
template<class any,class any1>
void add(any a,any1 b)
{
cout<<"the result is:";
cout<<a+b<<endl;
}
/*
template<class any,class any1>
void mul(any a,any1 b)
{
cout<<"the result is:";
cout<<a*b<<endl;
}*/
main()
{
add(20,10);
add(12.5,23.5);
add(20,10.5);
add(10.5,10);
//mul(10,20);
}
