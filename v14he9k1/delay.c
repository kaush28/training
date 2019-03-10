#include"types.h"

void delay(u16 dly)
{
u8 j;
for(;dly>0;dly--)
{
for(j=255;j>0;j--);
for(j=232;j>0;j--);
}
}
