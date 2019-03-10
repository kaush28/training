#include<stdio.h>
void swap(int a[10],int l,int h)
{
int temp;
temp=a[l];
a[l]=a[h];
a[h]=temp;
}
int partition(int a[10],int l,int h)
{
int pivot,left,right;
pivot=a[l];
left=l;
right=h;
while(left<right)
{
while(a[left]<=pivot)
left++;
while(a[right]>pivot)
right--;
if(left<right)
swap(a,left,right);
}
a[l]=a[right];
a[right]=pivot;
return right;
}
void quicksort(int a[10],int l,int h)
{
int pivot;
if(h>l)
{
pivot=partition(a,l,h);
quicksort(a,l,pivot-1);
quicksort(a,pivot+1,h);
}
}
main()
{
int i;
int a[10];
printf("enter the data: ");
for(i=0;i<10;i++)
{
scanf("%d",&a[i]);
}
quicksort(a,0,9);
printf("the sorted element:");
for(i=0;i<10;i++)
printf("%d",a[i]);
}
