#include<iostream>
using namespace std;
struct bank
{
int acc;
char name[20];
int balance;
int diposite(int amount)
{
balance+=amount;
cout<<"amount diposited successfully."<<endl;
return balance;
};
int withdraw(int amount)
{
if(amount>balance)
{
cout<<"insufficient amount."<<endl;
return balance;
}
else
{
balance-=amount;
cout<<"balance withdrawal successfully."<<endl;
return balance;
}
}
};
main()
{
int amount,option;
struct bank b;
cout<<"account no:";
cin>>b.acc;
cout<<"account holder name:";
cin>>b.name;
b.balance=0;
while(1)
{
cout<<"*****menu*****"<<endl;
cout<<"1:balance inquiry"<<endl;
cout<<"2:diposite"<<endl;
cout<<"3:withdrawal"<<endl;
cout<<"enter option: ";
cin>>option;
if(option==1)
{
cout<<"balance:"<<b.balance<<endl;
}
else if(option==2)
{
cout<<"enter the amount to diposite: ";
cin>>amount;
b.balance=b.diposite(amount);
}
else if(option==3)
{
cout<<"enter the amount to withdraw: ";
cin>>amount;
b.balance=b.withdraw(amount);
}
}
}
