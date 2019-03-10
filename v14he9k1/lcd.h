#ifndef LCD_H
#define LCD_H

#include"types.h"

extern void lcd_write(u8);
extern void lcd_char(u8);
extern void lcd_cmd(u8);
extern void lcd_init(void);
extern void lcd_str(u8*);
extern void lcd_int(u16);
extern void lcd_float(float);

#endif
