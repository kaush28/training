#ifndef I2C_H
#define I2C_H

#include"types.h"

extern void start(void);
extern void stop(void);
extern void write(u8);
extern void ack(void);
extern u8 read(void);
extern void noack(void);
extern void i2c_write(u8,u8,u8);
extern u8 i2c_read(u8,u8);

#endif
