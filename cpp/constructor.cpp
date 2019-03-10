#include<iostream>
using namespace std;
class height
{
int feet,inch;
public:
height(int f,int i)
{
feet=f;
inch=i;
}
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
~height()
{
//cout<<"in destructor:"<<endl;
cout<<feet<<"''"<<inch<<"'"<<endl;
//cout<<"exiting destructor"<<endl;
}
};
main()
{
height a3(0,0);
height a1(5,7);
height a2(5,6);
a3.sum(a1,a2);
}
