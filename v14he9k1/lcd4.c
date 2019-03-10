#include<reg51.h>
#include"types.h"
#include"delay.h"

bit flag;

sbit d7=P0^0;
sbit d6=P0^1;
sbit d5=P0^2;
sbit d4=P0^3;

sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void lcd_write(u8 val)
{
if(flag==0)
rs=0;

else
rs=1;

rw=0;
///////////////////////////////////
d7=(val&0x80)?1:0;
d6=(val&0x40)?1:0;
d5=(val&0x20)?1:0;
d4=(val&0x10)?1:0;
en=1;
en=0;


d7=(val&0x08)?1:0;
d6=(val&0x04)?1:0;
d5=(val&0x02)?1:0;
d4=(val&0x01)?1:0;
en=1;
en=0;
//////////////////////////////////
delay(2);
}

void lcd_char(u8 ch)
{
//rs=1;
flag=1;
lcd_write(ch);
}

void lcd_cmd(u8 val)
{
//rs=0;
flag=0;
lcd_write(val);
}

void lcd_init(void)
{                                                                                                                                                                                                                                                                                                                                                   
lcd_cmd(0x01);
lcd_cmd(0x02);
lcd_cmd(0x06);
lcd_cmd(0x0f);
lcd_cmd(0x28);
lcd_cmd(0x80);
}

void lcd_int(u16 no)
{
s8 i;
u8 a[5]={0};
if(no==0)
lcd_char('0');

for(i=0;i<5;i++)
{
a[i]=(no%10)+48;
no/=10;
}
for(--i;i>=0;i--)
{
lcd_char(a[i]);
}
}

void lcd_float(float f)
{
u16 t;
t=f;
lcd_int(t);
lcd_char('.');
f-=t;
f*=100;
t=f;
lcd_int(t);
}