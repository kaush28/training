#ifndef SPI_H
#define SPI_H
#include"types.h"

/* CHIP SELECT DECLARATION */


extern void Init_SPI(void);
extern u8 SPI(u8 c);
extern void CMD_2515(u8 CMD);
extern u8 BR_2515(u8 addr);
extern void modify_2515(u8 addr,u8 mask,u8 ch);
extern void BW_2515(u8 addr,u8 ch);

#endif