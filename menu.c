#include<stdio.h>
main()
{
int num,bit,out;
char ch;
printf("enter the number");
scanf("%d",&num);


printf("********menu*******\n");
printf("t for test\np for print\ns for set\nc for clear\nm for complement\nq for quit\n");
printf("enter your option:");
scanf(" %c",&ch);

if(ch=='t')
{
printf("enter the bit num",bit);
scanf("%d",&bit);
out=(num>>bit)&1;
printf("%d",out);
}
else if(ch=='p')
{
bit=31;
while(bit>=0)
{
out=(num>>bit)&1;
printf("%d",out);
bit--;
}
}

else if(ch=='s')
{
printf("enter the bit number");
scanf("%d",&bit);
num|=(1<<bit);
printf("%d",num);
}
else if(ch=='c')
{
printf("enter the bit");
scanf("%d",&bit);
num&=~(1<<bit);
printf("%d",num);
}
else if(ch=='m')
{
printf("enter the bit num");
scanf("%d",&bit);
num^=(1<<bit);
printf("%d",num);
}
else if(ch=='q')
return;
else
printf("invalid option");
}

