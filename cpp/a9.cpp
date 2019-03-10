#include<iostream>
using namespace std;
main()
{
int i,j,k,temp;
int buf[3][4];
cout<<"enter the elements of array: "<<endl;
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
{
cin>>buf[i][j];
}
}
cout<<"the 2d array is: "<<endl;
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
{
cout<<buf[i][j]<<"\t";
}
cout<<endl;
}
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
{
for(k=j+1;k<4;k++)
{
if(buf[i][j]>buf[i][k])
{
temp=buf[i][j];
buf[i][j]=buf[i][k];
buf[i][k]=temp;
}
}
}
}
cout<<"the sorted 2d array is:"<<endl;
for(i=0;i<3;i++)
{
for(j=0;j<4;j++)
{
cout<<buf[i][j]<<"\t";
}
cout<<endl;
}
}
