/*
 * 20-LDC.c
 *
 * Created: 8/5/2022 5:17:47 AM
 * Author : Islam Ashraf Mustafa
 */ 

#include <util/delay.h>
#define F_CPU 8000000UL
#include "LCD.h"


int main(void)
{
   LCD_vInit();
   LCD_vsend_string("islam ashraf mustafa");
   LCD_vsend_cmd(64);
   // ?
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00001000);
   LCD_vsend_char(0b00000000);
   // ?
    LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00010101);
	LCD_vsend_char(0b00011111);
	LCD_vsend_char(0b00000000); 
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	// ??
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00001001);
	LCD_vsend_char(0b00001010);
	LCD_vsend_char(0b00001111);
	LCD_vsend_char(0b00010000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	//?
	LCD_vsend_char(0b00001110);
	LCD_vsend_char(0b00001010);
	LCD_vsend_char(0b00001110);
	LCD_vsend_char(0b00001000);
	LCD_vsend_char(0b00001000);
	LCD_vsend_char(0b00001000);
	LCD_vsend_char(0b00001000);
	LCD_vsend_char(0b00000000);
	// ?
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00010101);
	LCD_vsend_char(0b00011111);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	// ?
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000010);
	LCD_vsend_char(0b00000100);
	LCD_vsend_char(0b00001100);
	LCD_vsend_char(0b00011000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	// ?
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000010);
	LCD_vsend_char(0b00000111);
	LCD_vsend_char(0b00000101);
	LCD_vsend_char(0b00011111);
	LCD_vsend_char(0b00000000);
	LCD_vsend_char(0b00000000);
	LCD_movecursor(2,16);
	LCD_vsend_char(0);
	LCD_movecursor(2,15);
	LCD_vsend_char(1);
	LCD_movecursor(2,14);
	LCD_vsend_char(2);
	LCD_movecursor(2,13);
	LCD_vsend_char(3);
	LCD_movecursor(2,11);
    LCD_vsend_char(0);
	LCD_movecursor(2,10);
	LCD_vsend_char(4);
	LCD_movecursor(2,9);
	LCD_vsend_char(5);
	LCD_movecursor(2,8);
	LCD_vsend_char(6);
	LCD_movecursor(2,7);
	DIO_write('B',RS,0);
	DIO_write('B',RW,0);
    while (1) 
    {
		LCD_vsend_cmd(0x18);
		_delay_ms(3000);
    }
	return 0;
}

