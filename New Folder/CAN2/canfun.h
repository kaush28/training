/* RECEIVER SECTION */
#ifndef CAN_H
#define CAN_H
#include"types.h"
extern void EXTINT0(void);
extern void init_ext(void);
extern void RSTDelay_CANCONTROLLER(void);
extern void init_CANCONTROLLER(void);
extern void RdBuf_2515(struct _RXBX_Buffer*RXBn_Buffer);
extern void CAN_Rx(void);

#endif
