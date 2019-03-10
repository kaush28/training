#include<iostream>
using namespace std;
class son;
class father
{
char name[20];
int age;
char company[20];
int salary;
int expenditure;
int total;
public:
father(void)
{
cout<<"enter the details:"<<endl;
cin>>name>>age>>company>>salary>>expenditure;
}
void display(void)
{
cout<<"name:"<<name<<endl;
cout<<"age:"<<age<<endl;
cout<<"company:"<<company<<endl;
cout<<"salary:"<<salary<<endl;
cout<<"expenditure:"<<expenditure<<endl;
}
~father()
{
cout<<"father in destructor:"<<endl;
}
void caltotincome(son &);
void caltotexpenditure(son &);
};
class son
{
char name[20];
int age;
char company[20];
int salary;
int expenditure;
public:
son(void)
{
cout<<"enter the details:"<<endl;
cin>>name>>age>>company>>salary>>expenditure;
}
void display(void)
{
cout<<"name:"<<name<<endl;
cout<<"age:"<<age<<endl;
cout<<"company:"<<company<<endl;
cout<<"salary:"<<salary<<endl;
cout<<"expenditure:"<<expenditure<<endl;
}
~son()
{
cout<<"son in destructor:"<<endl;
}
friend void father::caltotincome(son &);
friend void father::caltotexpenditure(son &);
};
void father::caltotincome(son &s)
{
total=salary+s.salary;
cout<<"total salary:"<<total<<endl;
}
void father::caltotexpenditure(son &s)
{
int spend,saving;
spend=expenditure+s.expenditure;
saving=total-spend;
cout<<"expenditure:"<<spend<<endl;
cout<<"saving:"<<saving<<endl;
}
main()
{
father f;
son s;
f.display();
s.display();
f.caltotincome(s);
f.caltotexpenditure(s);
}
