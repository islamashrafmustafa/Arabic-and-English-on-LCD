/*
 * CFile1.c
 *
 * Created: 8/5/2022 5:28:05 AM
 *  Author: Islam Ashraf Mustafa
 */ 

#include "DIO.h"
#include "LCD_config.h"
#define CLR_SCREEN 0x01
#define CURSOR_ON_DISPLAY_ON 0x0e
#define RETURN_HOME 0x02
#define ENTRY_MODE 0x06
#define EN 0
#define RS 2
#define RW 1
#if defined four_bit_mode
#define FOUR_BITS 0x28
#elif defined eight_bit_mode
#define EIGHT_BITS 0x38
#endif
void LCD_vInit(void);
static void send_falling_edge(void);
void LCD_vsend_cmd(char cmd);
void LCD_vsend_char(char data);
void LCD_vsend_string(char *data);
void LCD_clearscreen(void);
void LCD_movecursor(char row,char col);