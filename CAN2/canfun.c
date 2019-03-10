#include"headers.h"
u8 flg;
extern u8 ch;

//structure to hold the ID and data for receive data

struct _RXBX_Buffer
{
	u8 IS_RTR; //remote transmitt bit
	u16 RX_ID; //ID
	u8 RX_Len; //to hold the data length
	u8 RXBnD0; //to hold revd data
	u8 RX_Data[8];
}RXBX_Buffer;

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

void init_CANCONTROLLER(void)
{
	u8 Test_Char;
	Init_SPI();
	init_ext();
	CMD_2515(CMD_RESET);//sending the reset command to the mcp2515
	RSTDelay_CANCONTROLLER();//min reset delay for 2us
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

//functon used to read data to be received by mcp2515 and update the _RXBX_Buffer
void RdBuf_2515(struct _RXBX_Buffer*RXBn_Buffer)
{
	u8 Res,Tmp_RXBnCTRL,i;
	if(RXBn_Buffer->RXBnD0==RXB0D0)
	{
		RXBn_Buffer->RX_Len=BR_2515(RXB0DLC);
		Res=BR_2515(RXB0SIDH);
		RXBn_Buffer->RX_ID=(int)Res*8;
		Res=BR_2515(RXB0SIDL);
		Res>>=5;
		Res&=0x07;
		RXBn_Buffer->RX_ID+=Res;
		Tmp_RXBnCTRL=BR_2515(RXB0CTRL);
	}		
	else
	{
		RXBn_Buffer->RX_Len=BR_2515(RXB1DLC);
		Res=BR_2515(RXB1SIDH);
		RXBn_Buffer->RX_ID=(int)Res*8;
		Res=BR_2515(RXB1SIDL);
		Res>>=5;
		Res&=0x07;
		RXBn_Buffer->RX_ID+=Res;
		Tmp_RXBnCTRL=BR_2515(RXB1CTRL);
	}
	if(Tmp_RXBnCTRL & 0x08)
		RXBn_Buffer->IS_RTR=1;
	else
		RXBn_Buffer->IS_RTR=0;
	RXBn_Buffer->RX_Len &=0x0f;//get the actual length
	if(RXBn_Buffer->IS_RTR==0)
	{
	 cs=0;
	 Res=SPI(CMD_READ);
	 Res=SPI(RXBn_Buffer->RXBnD0);
	 for(i=0;i<RXBn_Buffer->RX_Len;i++)
	 {
	  Res=SPI(0xff);
	  RXBn_Buffer->RX_Data[i]=Res;
	 }
	 cs=1;
	}
	
}

//CAN RXing FUNCTION
void CAN_Rx(void)
{
	
	modify_2515(CANINTF,0x07,0x00);//clearing the interrupts
	while(flg==0)
	 RXBX_Buffer.RXBnD0=RXB0D0;
	RdBuf_2515(&RXBX_Buffer);
	flg=0;
	if(RXBX_Buffer.IS_RTR==0)
      ch=RXBX_Buffer.RX_Data[0];
	
}