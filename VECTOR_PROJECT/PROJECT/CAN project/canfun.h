  /* TRANSMITTER SECTION */
#ifndef CAN_H
#define CAN_H
#include "types.h"
extern void EXTINT0(void);
extern void init_ext(void);
extern void RSTDelay_CANCONTROLLER(void);
extern void init_CANCONTROLLER(void);
extern void WrBuf_CANCONTROLLER(struct _TXBX_Buffer*);
extern void CANframe_Tx(u8*,u8,u16,u8);

#endif