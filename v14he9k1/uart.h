#ifndef uart_h
#define uart_h

#include"types.h"

extern void init_uart(void);
extern void uart_tx(u8);
extern u8 uart_rx(void);
extern void str_tx(u8 *);

#endif
