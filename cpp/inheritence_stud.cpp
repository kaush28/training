#include<iostream>
using namespace std;
class student
{
protected:
char name[20];
int no;
public:
student(void)
{
cout<<"in student constructor:"<<endl;
cout<<"enter the name of student:";
cin>>name;
cout<<"enter the roll no:";
cin>>no;
}
void display()
{
cout<<"name:"<<name<<endl;
cout<<"roll:"<<no<<endl;
}
~student()
{
cout<<"in student destructor:"<<endl;
}
};

class department: virtual public student
//class department: public student
{
protected:
int m1,m2,m3;
public:
department()
{
cout<<"in department constructor:"<<endl;
cout<<"enter the marks:"<<endl;
cin>>m1>>m2>>m3;
}
void display()
{
student::display();
cout<<"academic marks:"<<endl;
cout<<m1<<" "<<m2<<" "<<m3<<endl;
}
~department()
{
cout<<"in department destructor:"<<endl;
}
};
class sports: virtual public student
//class sports: public student
{
protected:
int smark;
public:
sports()
{
cout<<"in sports constructor:"<<endl;
cout<<"enter the sports marks:";
cin>>smark;
}
void display()
{
cout<<"smarks:"<<smark<<endl;
}
~sports()
{
cout<<"in sports destructor:"<<endl;
}
};
class grade: public department, public sports
{
int total,avg;
public:
grade()
{
cout<<"in grade constructor:"<<endl;
total=m1+m2+m3+smark;
avg=total/4;
}
void display()
{
department::display();
sports::display();
if(avg<50)
cout<<"fail."<<endl;
else if(avg>=50 && avg<70)
cout<<"grade=c"<<endl;
else if(avg>=70 && avg<80)
cout<<"grade=b"<<endl;
else if(avg>=80 && avg<90)
cout<<"grade=a"<<endl;
else if(avg>=90)
cout<<"grade=a++"<<endl;
}
~grade()
{
cout<<"in grade destructor:"<<endl;
}
};
main()
{
//student *s;
//department *d;
grade g;
//s->display();
//d->display();
g.display();
}
