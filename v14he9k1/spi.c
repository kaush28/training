#include"types.h"



#include<reg51.h>


sfr p2=0xa0;
/*
sbit clk=P3^0;
sbit din=P3^2;
sbit dout=P3^1;
sbit _cs=P3^3;

float spi(u16 chno)
{
u8 i;
u16 adc_val=0;
bit d1,d0;

if(chno==0)
{
d1=d0=0;
}
else if(chno==1)
{
d1=0;
d0=1;
}
else if(chno==2)
{
d1=1;
d0=0;
}
else if(chno==3)
{
d1=d0=1;
}

//clk=din=dout=_cs=1;
_cs=
_cs=0;

clk=0; clk=1;

clk=0; clk=1;

clk=0; clk=1;

clk=0; din=d1; clk=1;

clk=0; din=d0; clk=1;

clk=0; clk=1;

clk=0; clk=1;

for(i=11;i>=0;i--)
{
clk=0;
if(dout)
{
adc_val|=1<<i;
}
clk=1;
}
_cs=1;
return(adc_val*(5.0/4095));
}

*/

//#include<reg51.h>
sbit _cs=p2^3;
sbit miso=p2^5;
sbit clk=p2^6;
sbit mosi=p2^4;
bdata chanNo;

float spi(bit d1,bit d0)
{
unsigned int adc_val=0;
char i; 

clk=mosi=1;//start condition for 3204

_cs=0;

clk=0;clk=1;//in mcp3201 that extra clock pulse not required
 
clk=0;mosi=1;clk=1;// used for single mode not differential mode

clk=0;mosi=1;clk=1;//d2 which is dont care
clk=0;mosi=d1;clk=1;//d1        d1  d2
clk=0;mosi=d0;clk=1;//d0         0   0   1st channel
                   //           0   1   2nd channel likewise 4 channel
clk=0;clk=1;       //sampling the data
clk=0;clk=1;       //for null
for(i=11;i>=0;i--) //for receiving 12 bit information
{
clk=0;
if(miso)
{
adc_val|=(1<<i);
}
clk=1;
}
_cs=1;
return ((adc_val*5.0)/4095);
}

