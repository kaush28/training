#include<stdio.h>
#include<math.h>
main()
{
int a,min_no,max_no,max,i,data;
printf("enter the min range: ");
scanf("%d",&min_no);
printf("enter the max rangr: ");
scanf("%d",&max_no);
if(min_no>max_no)
{
a=min_no;
min_no=max_no;
max_no=a;
}
for(data=min_no;data<=max_no;data++)
{
if((data==0)||(data==1)) data=2;
max=sqrt(data);
i=2;
for(i=2;i<=max;i++)
{
if(data%i==0) break;
}
if(i>max)
{
printf("%d,",data);
}
}
}
