#include"types.h"
#include<reg51.h>
#include"uart.h"
#include"delay.h"
#include"i2c.h"
#include<stdio.h>

code u8 *day[]={"monday","tuesday","wednesday","thursday","friday","saturday","sunday"};

u16 BCD2DEC(u16);

void edit(void);


u16 time[3];
u16 date[3];

main()
{
u16 d;
u16 a;

init_uart();

a=2;
TI=1;
printf("abcd\n");
printf("%0.2d:%0.2d:%0.2d",a,a,a);
TI=0;

i2c_write(0xd0,0x00,0x20);
i2c_write(0xd0,0x01,0x20);
i2c_write(0xd0,0x02,0x01);
i2c_write(0xd0,0x03,0x01);
i2c_write(0xd0,0x04,0x01);
i2c_write(0xd0,0x05,0x01);
i2c_write(0xd0,0x06,0x15);
i2c_write(0xd0,0x07,0x11);


while(1)
{
uart_tx(0x0c);

//////////////////////EDIT////////////////
if(RI==1)
edit();
//////////////////////////////////////////


///////////TIME///////////////////////
time[0]=i2c_read(0xd0,0x00);
time[0]=BCD2DEC(time[0]);


time[1]=i2c_read(0xd0,0x01);
time[1]=BCD2DEC(time[1]);

time[2]=i2c_read(0xd0,0x02);
time[2]=BCD2DEC(time[2]);
////////////////////////////////////

//////////DATE///////////////////////
date[0]=i2c_read(0xd0,0x04);
date[0]=BCD2DEC(date[0]);

date[1]=i2c_read(0xd0,0x05);
date[1]=BCD2DEC(date[1]);

date[2]=i2c_read(0xd0,0x06);
date[2]=BCD2DEC(date[2]);
/////////////////////////////////////

/////////DAY.///////////////////////
d=i2c_read(0xd0,0x03);
////////////////////////////////////
TI=1;
printf("HH:MM:SS   DD:MM:YY   DAY\n");
//str_tx("HH:MM:SS   DD:MM:YY   DAY\n");
//printf("%0.2bx:%0.2bx:%0.2bx   %0.2bx:%0.2bx:%0.2bx   ",time[2],time[1],time[0],date[0],date[1],date[2]);
//printf("%d:%d:%d   %d:%d:%d   ",time[2],time[1],time[0],date[0],date[1],date[2]);
printf("%0.2d:%0.2d:%0.2d   %0.2d:%0.2d:%0.2d   ",time[2],time[1],time[0],date[0],date[1],date[2]);
printf("%s\n",day[d-1]);
TI=0;
delay(1000);
}
}

u16 BCD2DEC(u16 dat)
{
u16 res=0;
res=((dat/16)*10)+(dat%16);
return res;
}

void edit(void)
{
u16 s;
u8 ch=0;
RI=0;
//ch=SBUF;
TI=1;
//printf("%c",ch);
TI=0;
//if((ch=='E')||(ch=='e'))
//{
TI=1;
printf("enter the option to edit:-");
printf("h:hour\nm:min\ns:sec\nd:date\nn:month\ny:year\na:day\n");
printf("enter your option:");
TI=0;
scanf("%c",&ch);
while(RI==0);

switch(ch)
{
case 'h':
		TI=1;
		printf("enter current hour:");
		
		scanf("%d",&time[2]);
       s=(time[2]/10)*16+time[2]%10;
	TI=0;
		i2c_write(0xd0,0x02,s);
		break;
case 'm':
		TI=1;
		printf("enter current minute:");
		
		scanf("%d",&time[1]);
	s=(time[1]/10)*16+time[1]%10;
		TI=0;
		i2c_write(0xd0,0x01,s);
		break;
case 's':
		TI=1;
		printf("enter current second:");
		
		scanf("%d",&time[0]);
s=(time[0]/10)*16+time[0]%10;
		TI=0;
		i2c_write(0xd0,0x01,s);
		break;
case 'd':
		TI=1;
		printf("enter current date:");
		
		scanf("%d",&date[0]);
		TI=0;
		i2c_write(0xd0,0x04,date[0]);
		break; 
case 'n':
		TI=1;
		printf("enter current month:");
	
		scanf("%d",&date[1]);
			TI=0;
		i2c_write(0xd0,0x05,date[1]);
		break;
case 'y':
		TI=1;
		printf("enter current year:");
	
		scanf("%d",&date[2]);
			TI=0;
		i2c_write(0xd0,0x06,date[2]);
		break;
case 'a':
		TI=1;
		printf("choose between 1 to 7: as 1 for monday:-");
		printf("enter current day:");
		TI=0;
		scanf("%d",&date[0]);
		i2c_write(0xd0,0x03,date[0]);
		break;
default: ;
}

//}
}
