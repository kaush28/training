#include"headers.h"
main()
{
 u8 P1=0x01;
 u8 P2=0x02;
 init_CANCONTROLLER();
 while(1)
 {
  //while(IS_ANYKEYPRESSED);
  while(IS_KEY1PRESSED)
   CANframe_Tx(&P1,0,MESSAGE_ID1,1);
   
  while(IS_KEY2PRESSED)
   CANframe_Tx(&P2,0,MESSAGE_ID2,1);
 }	
 return 0;								  
}