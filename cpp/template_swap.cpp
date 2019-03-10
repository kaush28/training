#include<iostream>
using namespace std;
template<class type>
void swap1(type &a,type &b)
{
//a^=b;
//b^=a;
//a^=b;
type temp;
temp=a;
a=b;
b=temp;
}
main()
{
int a,b;
char c,d;
float e,f;
double g,h;
cout<<"enter two numbers:";
cin>>a>>b;
swap1(a,b);
cout<<"after swapping:";
cout<<a<<b<<endl;
cout<<"enter two characters:";
cin>>c>>d;
swap1(c,d);
cout<<"after swapping:";
cout<<c<<d<<endl;
cout<<"enter two float numbers:";
cin>>e>>f;
swap1(e,f);
cout<<"after swapping:";
cout<<e<<f<<endl;
cout<<"enter two idouble numbers:";
cin>>e>>f;
swap1(e,f);
cout<<"after swapping:";
cout<<e<<f<<endl;
}
