#include<iostream>
using namespace std;
void swap(int i1,int i2)
{
int a;
a=i1;
i1=i2;
i2=a;
cout<<"data after swapping:";
cout<<"i1:"<<i1<<"i2:"<<i2<<endl;
}
void swap(float f1,float f2)
{
float a;
a=f1;
f1=f2;
f2=a;
cout<<"data after swapping:";
cout<<"f1:"<<f1<<"f2:"<<f2<<endl;
}
void swap(char str1[20],char str2[20])
{
char a[20];
strcpy(a,str1);
strcpy(str1,str2);
strcpy(str2,a);
cout<<"data after swapping:";
cout<<"str1:"<<str1<<"str2:"<<str2<<endl;
}
void swap(double d1,double d2)
{
double a;
a=d1;
d1=d2;
d2=a;
cout<<"data after swapping:";
cout<<"d1:"<<d1<<"d2:"<<d2<<endl;
}
main()
{
int i1=10,i2=20;
float f1=25.5,f2=50.5;
double d1=43.1,d2=51.2;
int option;
char str1[20]="vector",str2[20]="india";
cout<<"1:int swap"<<endl<<"2:float swap"<<endl<<"3:string swap"<<endl;
cout<<"4:double swap"<<endl;
cout<<"enter the option: "<<endl;
cin>>option;
if(option==1)
{
cout<<"data before swaping:";
cout<<"i1:"<<i1<<"i2:"<<i2<<endl;
swap(i1,i2);
}
else if(option==2)
{
cout<<"data before swaping:";
cout<<"f1:"<<f1<<"f2"<<f2<<endl;
swap(f1,f2);
}
else if(option==3)
{
cout<<"data before swaping:";
cout<<"str1:"<<str1<<"str2:"<<str2<<endl;
swap(str1,str2);
}
else if(option==4)
{
cout<<"data before swaping:";
cout<<"d1:"<<d1<<"d2:"<<d2<<endl;
swap(d1,d2);
}
}
