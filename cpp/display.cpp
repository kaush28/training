#include<iostream>
using namespace std;
inline void display(char str[20],float f)
//void display(char str[20],float f)
{
cout<<str<<endl;
cout<<f<<endl;
}
//inline void display(float f,int i,int a=20)
void display(float f,int i,int a=20)
{
cout<<f<<endl;
cout<<i<<endl;
cout<<"sum: "<<i+a<<endl;
}
inline void display(int i,double d)
//void display(int i,double d)
{
cout<<i<<endl;
cout<<d<<endl;
}
inline void display(double d,char str[20])
//void display(double d,char str[20])
{
cout<<d<<endl;
cout<<str<<endl;
}
inline void display(char str[20],float f,int i,double d)
//void display(char str[20],float f,int i,double d)
{
cout<<str<<endl;
cout<<f<<endl;
cout<<i<<endl;
cout<<d<<endl;
}
main()
{
char str[20]="vector";
float f=25.5;
int i=50;
double d=100;
display(str,f);
display(f,i);
display(i,d);
display(d,str);
display(str,f,i,d);
}
