#include<iostream>
using namespace std;
class array
{
int size,*arr;
public:
array()
{
int i;
cout<<"enter the size: ";
cin>>size;
arr=new int[size];
for(i=0;i<size;i++)
cin>>arr[i];
}
array(int *p,int cnt)
{
int i;
size=cnt;
arr=new int[size];
for(i=0;i<size;i++)
arr[i]=p[i];
}
void display(void)
{
int i;
for(i=0;i<size;i++)
cout<<arr[i]<<"\t";
cout<<endl;
}
~array()
{
int i;
cout<<"exiting the object"<<endl;
delete []arr;
//arr=NULL;
//for(i=0;i<size;i++)
//cout<<arr[i];
}
};
main()
{
array *a1;
a1=new array;
int a[5]={3,4,5,6,7};
a1->display();
array a2(a,5);
a2.display();
delete a1;
}
