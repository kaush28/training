#include<reg51.h>
#include"types.h"
#include"delay.h"
#include"spi1.h"

sbit clk=P3^0;
sbit dout=P3^1;
sbit din=P3^2;
sbit _cs=P3^3;

float adc_mcp3204(u8 chno)
{
u16 byte1=0,byte2=0;
u16 adc_val=0;
chno<<=6;

_cs=0;

spi1(6);
byte1=spi1(chno);
byte2=spi1(0);

_cs=1;

adc_val=((byte1&0x0f)<<8)|byte2;

return(adc_val*(5.0/4095));
}
