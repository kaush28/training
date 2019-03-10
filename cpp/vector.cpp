#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &v)
{
int i;
for(i=0;i<v.size();i++)
{
cout<<v[i]<<"\t";
}
cout<<endl;
}
main()
{
vector<int> v;
int option;
while(1)
{
cout<<"*****menu*****"<<endl;
cout<<"1:insert"<<endl;
cout<<"2:display"<<endl;
cout<<"3:size"<<endl;
cout<<"4:delete"<<endl;
cout<<"5:swap"<<endl;
cout<<"6:exit"<<endl;
cout<<endl<<endl;
cout<<"enter the option:";
cin>>option;
int data;
if(option==1)
{
cout<<"enter the data:";
cin>>data;
v.push_back(data);
}
else if(option==3)
{
cout<<v.size()<<endl;
}
else if(option==4)
{
int del;
cout<<"enter the data to delete:";
cin>>del;
//v.erase(v);
}
else if(option==5)
{
v.swap(v);
}
else if(option==2)
{
display(v);
}
else if(option==6)
{
return 0;
}
else
cout<<"invalid option."<<endl;
}
}
