#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
template<class any,class any1>
class array
{
any1 *p;//////////////
any size;
public:
array()
{
p=NULL;
size=0;
}
void insert(void)
{
size++;
p=(any1 *)realloc(p,size*sizeof(any1));
cout<<"enter the data:";
cin>>p[size-1];
}
void display(void)
{
any i;
for(i=0;i<size;i++)
cout<<p[i]<<"\t";
}
void delete1(void)
{
any i;
any1 del;
cout<<"enter the data to delete:";
cin>>del;
for(i=0;i<size;i++)
{
if(del==p[i])
break;
}
if(i==size)
cout<<"data not found."<<endl;
else
memmove(p+i,p+i+1,sizeof(any1)*(size-i-1));
size--;
p=(any1 *)realloc(p,size*sizeof(any1));
}
void search(void)
{
any i;
any1 find;
cout<<"enter the data to search:";
cin>>find;
for(i=0;i<size;i++)
{
if(find=p[i])
break;
}
if(i==size)
cout<<"data not found."<<endl;
else
cout<<"found."<<endl;
}
void reverse(void)
{
any1 temp;
any i,j;
for(i=0,j=size-1;i<j;i++,j--)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
void sort(void)
{
any1 temp;
any i,j;
for(i=0;i<size;i++)
{
for(j=i+1;j<size;j++)
{
if(p[i]>p[j])
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
}
};
main()
{
array<int,float> obj;
int option;
while(1)
{
cout<<endl;
cout<<"*****menu*****"<<endl;
cout<<"1:insert"<<endl;
cout<<"2:display"<<endl;
cout<<"3:delete"<<endl;
cout<<"4:search"<<endl;
cout<<"5:reverse"<<endl;
cout<<"6:sort"<<endl;
cout<<"7:quit"<<endl;
cout<<"enter the option:";
cin>>option;
if(option==1)
obj.insert();
else if(option==2)
obj.display();
else if(option==3)
obj.delete1();
else if(option==4)
obj.search();
else if(option==5)
obj.reverse();
else if(option==6)
obj.sort();
else if(option==7)
return 0;
else
cout<<"invalid option:"<<endl;

}
}
