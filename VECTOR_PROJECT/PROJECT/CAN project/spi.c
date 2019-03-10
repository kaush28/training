#include"headers.h"
/* SPI initialization func*/
void Init_SPI(void)
{
 SPCTL=0x50;
 cs=deselect;
}

/* SPI transfer fun def*/
u8 SPI(u8 c)
{
 SPCFG&=0x00;
 SPDAT=c;
 while(!(SPCFG));
 return(SPDAT);
}

/* funct to send command to mcp2515  */
void CMD_2515(u8 CMD)
{
 cs=select;
 SPI(CMD);
 cs=deselect;
}

void modify_2515(u8 addr,u8 mask,u8 ch)
{
 cs=select;
 SPI(CMD_MODIFY);
 SPI(addr);
 SPI(mask);
 SPI(ch);
 cs=deselect;
}
void BW_2515(u8 addr,u8 ch)
{
 cs=select;
 SPI(CMD_WRITE);
 SPI(addr);
 SPI(ch);
 cs=deselect;
}
u8 BR_2515(u8 addr)
{
 u8 ch;
 cs=select;
 SPI(CMD_READ);
 SPI(addr);
 ch=SPI(0xff);
 cs=deselect;
 return(ch);
}

