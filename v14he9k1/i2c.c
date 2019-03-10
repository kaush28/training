#include<reg51.h>
#include"types.h"
#include"delay.h"

sbit scl=P2^0;
sbit sda=P2^1;


void start(void)
{
scl=0;
sda=1;
scl=1;
sda=0;
}

void stop(void)
{
scl=0;
sda=0;
scl=1;
sda=1;
}

void write(u8 dat)
{
u8 i;
for(i=0;i<8;i++)
{
scl=0;
sda=(dat&(0x80>>i))?1:0;
scl=1;
}
}

u8 read(void)
{
u8 buff=0,i;
for(i=0;i<8;i++)
{
scl=0;
scl=1;
if(sda)
	buff|=0x80>>i;
}
return buff;
}

void ack(void)
{
scl=0;
sda=1;
scl=1;
while(sda);
}

void noack(void)
{
scl=0;
sda=1;
scl=1;
//sda=0;
}

void i2c_write(u8 saddr,u8 addr,u8 dat)
{
start();
write(saddr);
ack();
write(addr);
ack();
write(dat);
ack();
stop();
delay(10);
}

u8 i2c_read(u8 saddr,u8 addr)
{
u8 buff=0;
start();
write(saddr);
ack();
write(addr);
ack();
start();
write(saddr|01);
ack();
buff=read();
noack();
stop();
return buff;
}
