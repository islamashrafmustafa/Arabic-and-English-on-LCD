/*
 * LCD.c
 *
 * Created: 8/5/2022 6:02:51 AM
 *  Author: Islam Ashraf Mustafa
 */ 

#include "LCD.h"
#include <util/delay.h>
#define F_CPU 8000000UL

void LCD_vInit(void)
{
#if defined eight_bit_mode
_delay_ms(200);
for (int counter=0;counter<8;counter++)
{
DIO_vsetPINDir('A',counter,1);
}
DIO_vsetPINDir('B',EN,1);
DIO_vsetPINDir('B',RS,1);
DIO_vsetPINDir('B',RW,1);
DIO_write('B',RW,0);
LCD_vsend_cmd(EIGHT_BITS);
_delay_ms(1);
LCD_vsend_cmd(CURSOR_ON_DISPLAY_ON);
_delay_ms(1);
LCD_vsend_cmd(CLR_SCREEN);
_delay_ms(10);
LCD_vsend_cmd(ENTRY_MODE);
_delay_ms(1);
#elif defined four_bit_mode
_delay_ms(200);
for (int counter=5;counter<8;counter++)
{
DIO_vsetPINDir('A',counter,1);
}
DIO_vsetPINDir('B',EN,1);
DIO_vsetPINDir('B',RS,1);
DIO_vsetPINDir('B',RW,1);
DIO_write('B',RW,0);
LCD_vsend_cmd(RETURN_HOME);
_delay_ms(10);
LCD_vsend_cmd(FOUR_BITS);
_delay_ms(1);
LCD_vsend_cmd(CURSOR_ON_DISPLAY_ON);
_delay_ms(10);
LCD_vsend_cmd(CLR_SCREEN);
_delay_ms(1);
LCD_vsend_cmd(ENTRY_MODE);
_delay_ms(1);
#endif
}

static void send_falling_edge(void)
{
DIO_write('B',EN,1);
_delay_ms(4);
DIO_write('B',EN,0);
_delay_ms(4);
}

void LCD_vsend_cmd(char cmd)
{
#if defined eight_bit_mode
DIO_write_port('A',cmd);
DIO_write('B',RS,0);
send_falling_edge();
_delay_ms(1);
#elif defined four_bit_mode
DIO_write_high_nibble('A',cmd>>4);
DIO_write('B',RS,0);
send_falling_edge();
DIO_write_high_nibble('A',cmd);
DIO_write('B',RS,0);
send_falling_edge();
_delay_ms(1);
#endif
}

void LCD_vsend_char(char data)
{
#if defined eight_bit_mode
DIO_write_port('A',data);
DIO_write('B',RS,1);
send_falling_edge();
_delay_ms(1);
#elif defined four_bit_mode
DIO_write_high_nibble('A',data>>4);
DIO_write('B',RS,1);
send_falling_edge();
DIO_write_high_nibble('A',data);
DIO_write('B',RS,1);
send_falling_edge();
_delay_ms(1);
#endif
}

void LCD_vsend_string(char *data)
{
while((*data)!='\0')
{
LCD_vsend_char( *data);
data++;
}
}

void LCD_clearscreen(void)
{
 LCD_vsend_cmd(CLR_SCREEN);
_delay_ms(10);
}

void LCD_movecursor(char row,char col)
{
char data;
if (row>2||row<1||col>16||col<1)
{
data=0x80+col-1;
}
else if(row==1)
{
	data=0x80+col-1;
}
else if (row==2)
{
data=0xc0+col-1;
}
LCD_vsend_cmd(data);
_delay_ms(1);
}