#include"reg51.h"
#include"types.h"
#include"delay.h"

code u8 lit[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
u8 dp1=0xff, dp2=0xff, dp3=0xff, dp4=0xff;

#define SEG_PORT P0
sbit sel1=P1^0;
sbit sel2=P1^1;
sbit sel3=P1^2;
sbit sel4=P1^3;

void seg7_number(int num)
{
SEG_PORT=lit[num/1000]&dp1;
sel1=0;
delay(1);
sel1=1;

SEG_PORT=lit[(num/100)%10]&dp2;
sel2=0;
delay(1);
sel2=1;

SEG_PORT=lit[(num%100)/10]&dp3;
sel3=0;
delay(1);
sel3=1;

SEG_PORT=lit[num%10]&dp4;
sel4=0;
delay(1);
sel4=1;

}

void seg7_float(float f)
{
u16 i;
//dp1=dp2=dp3=dp4=0xff;

if((f>=0.0)&&f<(10.0))
{
i=f*1000;
dp1=0x7f;
}
else if((f>=10.0)&&(f<100.0))
{
i=f*100;
dp2=0x7f;
}
else if((f>=100.0)&&(f<1000.0))
{
i=f*10;
dp3=0x7f;
}
else
i=f;

seg7_number(i);
}
