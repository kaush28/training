#include<stdio.h>
main()
{
int unit;
float charge;
printf("enter the power unit consumed: ");
scanf("%d",&unit);
if(unit<=200)
{
charge=unit*0.50;
}
else if((unit>200)&&(unit<=400))
{
charge=100+((unit-200)*0.65);
}
else if((unit>400)&&(unit<=600))
{
charge=230+((unit-400)*0.80);
}
else if(unit>600)
{
charge=390+((unit-600)*1);
}
printf("total unit consumed is %d and amount to be paid is %f\n",unit,charge);
}

