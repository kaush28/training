#include<reg51.h>
#include"types.h"
#include"delay.h"

#define lcd_data P0

sbit rs=P2^0;
sbit rw=P2^1;
sbit en=P2^2;

void lcd_write(u8 val)
{
lcd_data=val;
rw=0;
en=1;
en=0;
delay(2);
}

void lcd_char(u8 ch)
{
rs=1;
lcd_write(ch);
}

void lcd_cmd(u8 val)
{
rs=0;
lcd_write(val);
}

void lcd_init(void)
{
/*
delay(16);
lcd_cmd(0x30);
delay(5);
lcd_cmd(0x30);
delay(1);
lcd_cmd(0x02);
lcd_cmd(0x38);
lcd_cmd(0x06);
lcd_cmd(0x01);
lcd_cmd(0x0f);
*/
//lcd_cmd(0x80);
//delay(10);

//lcd_cmd(0x80);

lcd_cmd(0x02);//return home
lcd_cmd(0x38);//2 line 5x7 matrix selection with 8-bit mode
lcd_cmd(0x0c);//display on cursor off
lcd_cmd(0x06);//shift cursor to right
lcd_cmd(0x01);//clear screen
lcd_cmd(0x80);//1st line 1st postion                                                                                                                                                                                                                                                                                                                                                    

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
