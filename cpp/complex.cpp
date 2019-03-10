#include<iostream>
using namespace std;s
class complex1
{
int real,img;
public:
complex1()
{
real=0;
img=0;
}
complex1(int i,int j)
{
real=i;
img=j;
}
//////////////////addition//in class//////////////////
complex1 operator+(complex1 &x)
{
complex1 temp;
temp.real=real+x.real;
temp.img=img+x.img;
return temp;
}
///////////subtraction///in class///////////////////
complex1 operator-(complex1 &x)
{
complex1 temp;
temp.real=real-x.real;
temp.img=img-x.img;
return temp;
}
//////////friend declaration/////////////////////
friend void display(complex1 &);
friend complex1 operator++(complex1 &);
friend complex1 operator--(complex1 &);
friend complex1 operator++(complex1 &,int);
friend complex1 operator--(complex1 &,int);
};
////////////display//////////////////////////////
void display(complex1 &x)
{
if(x.img<0)
cout<<x.real<<x.img<<"i"<<endl;
else
cout<<x.real<<"+"<<x.img<<"i"<<endl;
}
/////////////////pre increment/////////////////////////
complex1 operator++(complex1 &x)
{
++x.real;
++x.img;
return x;
}
//////////////pre decrement//////////////////////////////
complex1 operator--(complex1 &x)
{
--x.real;
--x.img;
return x;
}
//////////////post increment/////////////////////////////////
complex1 operator++(complex1 &x,int n)
{
complex1 temp;
temp.real=x.real++;
temp.img=x.img++;
return temp;
}
////////////post decrement/////////////////////////////
complex1 operator--(complex1 &x,int n)
{
complex1 temp;
temp.real=x.real--;
temp.img=x.img--;
return temp;
}
main()
{
complex1 e1(10,-10);
display(e1);
complex1 e2(15,20);
display(e2);
complex1 e3;
e3=e1+e2;
display(e3);
e3=e1-e2;
display(e3);
++e1;
display(e1);
--e1;
display(e1);
complex1 e4;
e4=e1++;
display(e4);
display(e1);
e4=e1--;
display(e4);
display(e1);
}
