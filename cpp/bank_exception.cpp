#include<iostream>
using namespace std;
class sbi;
class boi;
//friend void display(boi &,sbi &);
////////////////////////////////////////////////////////////
class sbi
{
char name[20];
int no;
int balance;
public:
sbi()
{
cout<<"in sbi constructor:"<<endl;
cout<<"enter the information:"<<endl;
cout<<"enter the name:";
cin>>name;
cout<<"enter the account number: ";
cin>>no;
cout<<"ener the balance: ";
cin>>balance;
}
void credit(int sum);
void withdrawal(int sum);
void transfer(boi &b);
friend void display(boi &,sbi &);
};
//////////////////////////////////////////////////////////
class boi
{
public:
char name[20];
int no;
int balance;
public:
boi()
{
cout<<"in boi constructor:"<<endl;
cout<<"enter the information:"<<endl;
cout<<"enter the name:";
cin>>name;
cout<<"enter the account number: ";
cin>>no;
cout<<"ener the balance: ";
cin>>balance;
}
void credit(int sum)
{
balance+=sum;
cout<<"the balance is credited to your account."<<endl;
}
//////////////////////////////////////////////////////////////
void withdrawal(int sum)
{
try
{
if(sum<balance)
balance-=sum;

else
throw "";
}
catch(...)
{
cout<<"insuficient balance."<<endl;
}
}
friend void display(boi &,sbi &);
friend void sbi::transfer(boi &);
};
///////////////////////////////////////////////////////////
void sbi::credit(int sum)
{
balance+=sum;
cout<<"the balance is credited to your account."<<endl;
}
//////////////////////////////////////////////////////////
void sbi::withdrawal(int sum)
{
try
{
if(sum<balance)
balance-=sum;
else
throw "";
}
catch(...)
{
cout<<"insuficient balance."<<endl;
}
}
/////////////////////////////////////////////////////////
void sbi::transfer(boi &b)
{
int sum;
cout<<"enter the amount to transfer:";
cin>>sum;
if(sum<balance)
{
balance-=sum;
b.credit(sum);
}
else
cout<<"insufficient fund."<<endl;
}
/////////////////////////////////////////////////////
void display(boi &b,sbi &s)
{
cout<<"the details of boi account is:"<<endl;
cout<<"name:"<<b.name<<endl;
cout<<"acco no.:"<<b.no<<endl;
cout<<"balance:"<<b.balance<<endl;
cout<<"the details of sbi account is:"<<endl;
cout<<"name:"<<s.name<<endl; 
cout<<"acc no.:"<<s.no<<endl;
cout<<"balance:"<<s.balance<<endl;
}
////////////////////////////////////////////////////////
main()
{
sbi s;
boi b;
int option,sum;
while(1)
{
cout<<"*****menu*****"<<endl;
cout<<"1:credit to sbi"<<endl;
cout<<"2:withdrawal from sbi"<<endl;
cout<<"3:crdit to boi"<<endl;
cout<<"4:withdrawal from boi"<<endl;
cout<<"5:display"<<endl;
cout<<"6:transfer to sbi"<<endl;
cout<<"7:transfer to boi"<<endl;
cout<<"8:exit"<<endl<<endl;
cout<<"enter the option:";
cin>>option;
switch(option)
{
case 1:
	cout<<"enter the amont to credit to sbi:";
	cin>>sum;
	s.credit(sum);
	break;
case 2:
	cout<<"enter the amount to withdraw from sbi";
	cin>>sum;
	s.withdrawal(sum);
	break;
case 3:
	cout<<"enter the amount to credit to boi:";
	cin>>sum;
	b.credit(sum);
	break;
case 4:
	cout<<"enter the amount to withdraw from boi:";
	cin>>sum;
	b.withdrawal(sum);
	break;
case 5:
	display(b,s);
	break;
case 6:
//	b.transfer(s);
	break;
case 7:
	s.transfer(b);
	break;
case 8:
	return 0;
default:
	cout<<"invalid input."<<endl;
}
}
}
