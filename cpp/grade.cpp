#include<iostream>
using namespace std;
class student
{
char name[20];
int roll;
int marks[5];
public:
void data_entry(void)
{
int i=0;
cout<<"enter student name: ";
cin>>name;
cout<<"roll no: ";
cin>>roll;
cout<<"marks for the subjects: ";
for(i=0;i<5;i++)
cin>>marks[i];
};
void display(void)
{
int i;
cout<<"student name: "<<name<<endl;
cout<<"roll no: "<<roll<<endl;
cout<<"marks for s subjects: ";
for(i=0;i<5;i++)
cout<<marks[i]<<" ";
};
void grade(void)
{
int sum=0,i,avg;
for(i=0;i<5;i++)
sum+=marks[i];
avg=sum/5;
if(avg<50)
cout<<"status:"<<"fail"<<endl;
else if(avg>=50)
cout<<"status:"<<"pass"<<endl;
};
};
main()
{
student stud;
stud.data_entry();
stud.display();
stud.grade();
}
