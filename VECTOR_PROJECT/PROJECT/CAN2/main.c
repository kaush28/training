#include"headers.h"

u8 ch;
u8 i;
main()
{
 init_CANCONTROLLER();
 while(1)
 {
  CAN_Rx();
  if(ch==0x01)
  {
   LED1=0;
   LED2=1;
  }
  if(ch==0x02)
  {
   LED2=0;
   LED1=1;
  }
 }
 return 0;
}