
#include<stdio.h>
int sum(int,int);
int difference(int,int);
int product(int,int);
int division(int,int);
main()
{
int a,b,result,choice;
printf("enter the value of a: ");
scanf("%d",&a);
printf("enter the value of b: ");
scanf("%d",&b);
printf("\n1:sum\n2:difference\n3:product\n4:division\n");
printf("enter the choice: ");
scanf("%d",&choice);
if(choice==1)
result=sum(a,b);
else if(choice==2)
result=difference(a,b);
else if(choice==3)
result=product(a,b);
else if(choice==4)
result=division(a,b);
printf("result=%d\n",result);
}
