#include<stdio.h>
main()
{
float basic,house,gross,perks,tax,net;
int level;
printf("enter the level and basic pay: ");
scanf("%d",&level);
scanf("%f",&basic);
		if(level==1)
		gross=(basic+(basic/4)+1500);
		else if(level==2)
		gross=(basic+(basic/4)+950);
		else if(level==3)
		gross=(basic+(basic/4)+600);
		else if(level==4)
		gross=(basic+(basic/4)+250);
printf("gros salary=%f",gross);
if(gross<=2000)
{
tax=0;
net=(gross-tax);
}
else if(gross>2000&&gross<=4000)
{
tax=gross*0.03;
net=(gross-tax);
}
else if(gross>4000&&gross<=5000)
{
tax=gross*0.05;
net=(gross-tax);
}
else if(gross>5000)
{
tax=gross*0.08;
net=(gross-tax);
}
printf("\nnet salary=%f\n",net);
}
