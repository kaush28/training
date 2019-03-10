#include<iostream>
using namespace std;
class height
{
char *name;
int feet,inch;
public:
height(int f,int i)
{
char ptr[20];
cin>>ptr;
name=new char[strlen(ptr)+1];
strcpy(name,ptr);
feet=f;
inch=i;
}
void getdata(void)
{
char p[20];
cin>>p;
strcpy(name,p);
cin>>feet>>inch;
}
/*
void sum(height &a1,height &a2)
{
feet=a1.feet+a2.feet;
inch=a1.inch+a2.inch;
while(inch>=12)
{
feet++;
inch-=12;
}
}
*/
~height()
{
//cout<<"in destructor:"<<endl;
cout<<name<<endl;
cout<<feet<<"''"<<inch<<"'"<<endl;
//cout<<"exiting destructor"<<endl;
}
};
main()
{
//height a3(0,0);
height a1(5,7);
height a4=a1;
a1.getdata();
//height a2(5,6);
//a3.sum(a1,a2);
}
