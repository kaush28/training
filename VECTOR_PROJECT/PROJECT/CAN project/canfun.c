#include"headers.h"
char flg;

//structure to hold the ID and data for transmitting

struct _TXBX_Buffer
{
	u8 IS_RTR; //remote transmitt bit
	u16 TX_ID; //ID
	u8 TX_Len; //to hold the data length
	u8 TXBnD0;
	u8 TX_Data[8];
}TXBX_Buffer;

/* ISR ROUTINE */
void EXTINT0(void)interrupt 0
{
	flg=1;
	IE0=0; //clear interrupt
}

/* INTERRUPT INITIALIZATION FUNCTION*/

void init_ext(void)
{
	IEN0|=0x81;
	IT0=1;
}

//delay routine for MCP2515 after reset
void RSTDelay_CANCONTROLLER(void)
{
	u8 i;
	for(i=70;i>0;i--);//delay for 140us
}

void Init_CANCONTROLLER(void)
{
	u8 Test_Char;
	Init_SPI();
	init_ext();
	CMD_2515(CMD_RESET);//sending the reset command to the mcp2515
	RSTDelay_CANCONTROLLER();
	modify_2515(CANCTRL,MODE_MASK,MODE_CONFIG);//setting the mcp2515 n configure mode
	modify_2515(CANCTRL,CLK_MASK,CLK_BITS);
	//setting the configuration bits based on bit timming
	BW_2515(CNF1,BRP_BITS);
	BW_2515(CNF2,CONFIG_PSPH1);
	BW_2515(CNF3,CONFIG_PH2);
	BW_2515(CANINTE,INT_ENABLE); //enabling the interrupts
	//enabling the receive buffer contrl register
	BW_2515(RXB0CTRL,RxBuf0_Mode);
	BW_2515(RXB1CTRL,RxBuf1_Mode);
	modify_2515(BFPCTRL,RXPINENABLE_MASK,RXPINENABLE);
	//checking loopback mode
	do
	{
		modify_2515(CANCTRL,MODE_MASK,MODE_LOOPBACK);
//set to loopback mode
    Test_Char=BR_2515(CANSTAT);
    Test_Char&=MODE_MASK;		
	}while(Test_Char!=MODE_LOOPBACK);
	modify_2515(CANCTRL,MODE_MASK,MODE_NORMAL);
}

//functon used to write data to be transmitted to mcp2515
void WrBuf_CANCONTROLLER(struct _TXBX_Buffer *TXBn_Buffer)
{
	u8 Res,l,i;
	l=TXBn_Buffer->TX_Len;
	if(TXBn_Buffer->IS_RTR==1)
		TXBn_Buffer->TX_Len|=0x40;//set RTR bit
	switch(TXBn_Buffer->TXBnD0)
  {
		case TXB0D0:
			BW_2515(TXB0SIDH,(unsigned char)((TXBn_Buffer)->TX_ID>>3)&0xff);
		  BW_2515(TXB0SIDL,(unsigned char)((TXBn_Buffer)->TX_ID>>5)&0xE0);
		  BW_2515(TXB0DLC,TXBn_Buffer->TX_Len);
	  	break;
		case TXB1D0:
			BW_2515(TXB1SIDH,(unsigned char)((TXBn_Buffer)->TX_ID>>3)&0xff);
		  BW_2515(TXB1SIDL,(unsigned char)((TXBn_Buffer)->TX_ID>>5)&0xE0);
		  BW_2515(TXB1DLC,TXBn_Buffer->TX_Len);
		  break;
		case TXB2D0:
			BW_2515(TXB2SIDH,(unsigned char)((TXBn_Buffer)->TX_ID>>3)&0xff);
		  BW_2515(TXB2SIDL,(unsigned char)((TXBn_Buffer)->TX_ID>>5)&0xE0);
		  BW_2515(TXB2DLC,TXBn_Buffer->TX_Len);
		  break;
	}
cs=select;
	if(l!=0)
	{
		Res=SPI(CMD_WRITE);
		Res=SPI(TXBn_Buffer->TXBnD0);
		for(i=0;i<l;i++)
		  Res=SPI(TXBn_Buffer->TX_Data[i]);
}
cs=deselect;
}

//CAN TRANSMISION FUNCTION
void CANframe_Tx(u8 *p,u8 RTR,u16 MESSAGE_ID,u8 l)
{
	TXBX_Buffer.TX_Len=1;
	for(;l>0;l--)
	  TXBX_Buffer.TX_Data[l-1] = *(p+l-1);
	TXBX_Buffer.IS_RTR=RTR;
	TXBX_Buffer.TX_ID=MESSAGE_ID;
	TXBX_Buffer.TXBnD0=TXB0D0;
	WrBuf_CANCONTROLLER(&TXBX_Buffer);
	flg=0;
	CMD_2515(CMD_RTS0);
	while(flg==0);//waiting for the data to be transmitted 
	modify_2515(CANINTF,0x07,0x00);//clearing the interrupts
	
}