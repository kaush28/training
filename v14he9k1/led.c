#include"types.h"
#include"reg51.h"
#include"delay.h"

#define LED_PORT P2

void led_display(u16 i)
{
//while(1)
//{
LED_PORT=0x0f;
//delay(1000);
//LED_PORT=0x00;
//delay(1000);
LED_PORT^=i;
//}
}
