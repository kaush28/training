#include<reg51.h>
#include"types.h"
#include"delay.h"

sbit clk=P3^0;
sbit dout=P3^1;
sbit din=P3^2;

u8 spi1(u8 dat)
{
u8 i, buff=0;
for(i=0;i<8;i++)
{
clk=0;
din=dat&(0x80>>i)?1:0;
if(dout)
buff|=(0x80)>>i;
clk=1;
}
return buff;
}
