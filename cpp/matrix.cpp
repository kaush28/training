#include<iostream>
using namespace std;
class matrix
{
int row,col;
int **p;
public:
matrix()
{
int i;
cout<<"enter the row and column value:";
cin>>row>>col;
p=new int*[row];
for(i=0;i<row;i++)
*(p+i)=new int[col];
cout<<"entering the data: "<<endl;
for(i=0;i<row;i++)
for(int j=0;j<col;j++)
cin>>p[i][j];
}
void display(void)
{
int i,j;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
cout<<p[i][j];
cout<<"\t";
}
cout<<endl;
}
}
void sort_row(void)
{
int i,j,k,l;
for(i=0;i<row;i++)
{
for(j=0;j<col;j++)
{
for(k=j+1;k<col;k++)
{
if(p[i][j]>p[i][k])
{
l=p[i][j];
p[i][j]=p[i][k];
p[i][k]=l;
}
}
}
}
}
void sort_col(void)
{
int i,j,k,l;
for(i=0;i<col;i++)
{
for(k=0;k<row;k++)
{
for(j=k+1;j<row;j++)
{
if(p[k][i]>p[j][i])
{
l=p[k][i];
p[k][i]=p[j][i];
p[j][i]=l;
}
}
}
}
}
~matrix()
{
cout<<"memory deallocation:"<<endl;
delete p;
p=NULL;

}
};
main()
{
matrix sort;
sort.display();
sort.sort_row();
cout<<endl<<endl<<endl;
sort.display();
sort.sort_col();
cout<<endl<<endl<<endl;
sort.display();
}
