#include<iostream>
#include<cstring>
using namespace std;
class person
{
protected:
char name[20];
int age;
public:
person(char *n,int a)
{
cout<<"in person's constructor:"<<endl;
strcpy(name,n);
age=a;
}
void display()
{
cout<<"name:"<<name<<endl;
cout<<"age:"<<age<<endl;
}
~person()
{
cout<<"in person's destructor:"<<endl;
}
};
class student:public person
{
int id,salary;
char company[20],designation[20];
public:
student(char *n,int a,int i,int s,char *c,char *d):person(n,a)
{
cout<<"in student constructor:"<<endl;
strcpy(name,n);
age=a;
id=i;
salary=s;
strcpy(company,c);
strcpy(designation,d);
}
void display()
{
person::display();
cout<<"id:"<<id<<endl;
cout<<"salary:"<<salary<<endl;
cout<<"company:"<<company<<endl;
cout<<"designation:"<<designation<<endl;
}
void hike()
{
int qualification,experience;
int amount;
cout<<"calculating the hike amount:"<<endl;
cout<<"enter the type of qualification:";
cin>>qualification;
cout<<"enter the years of experience:";
cin>>experience;
amount=experience*qualification;
salary+=(salary*amount*3)/100;
cout<<"new salary:"<<salary<<endl;
}
~student()
{
cout<<"in student destructor:"<<endl;
}
};
main()
{
student s("aaaa",45,123,30000,"xyz","abc");
s.display();
s.hike();
}
