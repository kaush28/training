#include<stdio.h>
void fibonacii(int);
main()
{
int no;
printf("enter the no in series: ");
scanf("%d",&no);
fibonacii(no);
}
void fibonacii(int no)
{
int sum,a=0,b=1;
while(no)
{
sum=a+b;
a=b;
b=sum;
printf("%d,",sum);
no--;
}

}
