#include<iostream>
using namespace std;
//////////////////////////////////////////////////////////////////
class bank;
class shopping
{
int n,i,total;
char ch;
int price[5];
public:
void online(bank &b);
};
class bank
{
char name[20];
int no;
int saving;
public:
bank(void)
{
cout<<"enter the details:"<<endl;
cin>>name>>no>>saving;
}
void submit(void)
{
int amount;
cout<<"enter the amount to submit:"<<endl;
cin>>amount;
saving+=amount;
}
void withdraw(int amount)
{
if(amount<saving)
{
saving-=amount;
}
else
cout<<"insufficient fund."<<endl;
}
void display()
{
cout<<"name:"<<name<<endl;
cout<<"no:"<<no<<endl;
cout<<"saving:"<<saving<<endl;
}
friend void shopping::online(bank &);
};
//////////////////////////////////////////////////////
void shopping::online(bank &b)
{
int total=0;
cout<<"enter the no of materials:"<<endl;
cin>>n;
for(i=0;i<n;i++)
{
cin>>price[i];
}
for(i=0;i<n;i++)
{
total+=price[i];
}
cout<<"are you sure want to purchase the item:(y/n)"<<endl;
cin>>ch;
if(ch=='y')
{
b.withdraw(total);
}
}
//////////////////////////////////////////////////////////////////
main()
{
int sum;
char ch;
class bank b;
class shopping s;
while(1)
{
cout<<"*****menu*****"<<endl;
cout<<"s:submit"<<endl<<"d:display"<<endl<<"w:withdrawal"<<endl<<"o:shopping"<<endl;
cout<<"enter your option";
cin>>ch;
switch(ch)
{
case 's':
	b.submit();
	break;
case 'w':
	cout<<"enter the sum to withdraw:";
	cin>>sum;
	b.withdraw(sum);
	break;
case 'o':
	s.online(b);
	break;	
case 'd':
	b.display();
	break;
}
}
}
