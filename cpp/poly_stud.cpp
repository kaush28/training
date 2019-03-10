#include<iostream>
using namespace std;
class student
{
//protected:
char name[20];
int roll;
public:
student()
{
cout<<"in student constructor:"<<endl;
cout<<"enter the student name:";
cin>>name;
cout<<"enter the roll no:";
cin>>roll;
}
virtual void display()
{
cout<<"in student display:"<<endl;
cout<<"name:"<<name<<endl;
cout<<"roll no.:"<<roll<<endl;
}
virtual ~student()
{
cout<<"in student destructor:"<<endl;
}
};
class department: public student
{
int m1,m2,m3;
public:
department()
{
cout<<"in department constructor:"<<endl;
cout<<"enter the marks of student:";
cin>>m1>>m2>>m3;
}
void display()
{
//student::display();
cout<<"display of department:"<<endl;
cout<<"marks of student:"<<endl;
cout<<m1<<" "<<m2<<" "<<m3<<endl;
}
~department()
{
cout<<"in department destructor:"<<endl;
}
};
main()
{
student *p;
p=new department;
p->display();
delete p;
}
