#include <avr/io.h>

#define LCD_PORT PORTD
#define LCD_DDR DDRD

#if (!defined LCD_DDR || !defined LCD_PORT)
#warning "Please define LCD_DDR and LCD_PORT"
#define LCD_DDR DDRB
#define LCD_PORT PORTB


#endif 

#ifndef LCD_RS
#warning "LCD using default pin".
#define LCD_RS 0
#define LCD_RW 2
#define LCD_EN 2
#define LCD_D0 4
#define LCD_D1 5
#define LCD_D2 6
#define LCD_D3 7

#endif

#define LCD_COL_COUNT 16 // Kolumner på LCD skärmen
#define LCD_ROW_COUNT 2  // Amtalet rader på LCD_skärmen

#define LCD_CLEARDISPLAY 0x01
#define LCD_RETURNHOME 0x02
#define LCD_ENTRYMODESET 0x04
#define LCD_DISPLAYCONTROL 0x08
#define LCD_CURSORSHIFT 0x10
#define LCD_FUNCTIONSET 0X20
#define LCD_SETGRAMADDR 0x40
#define LCD_SETDDRAMADDR 0x80

#define LCD_ENTRYRIGHT 0x00
#define LCD_ENTRYLEFT 0x02
#define LCD_ENTRYSHIFTINCREMENT 0x01
#define LCD_ENTRYSHIFTDECREMENT 0x00

#define LCD_DISPLAYON 0x04
#define LCD_DISPLAYOFF 0x00
#define LCD_CURSORON 0x01
#define LCD_CURSOROFF 0x00
#define LCD_BLINKON 0x01
#define LCD_BLINKOFF 0x00

#define LCD_DISPLAYMOVE 0x08
#define LCD_CURSORMODE 0x00
#define LCD_MOVERIGHT 0x04
#define LCD_MOVELEFT 0x00

#define LCD_8BITMODE 0x10
#define LCD_4BITMODE 0x00
#define LCD_2LINE 0x08
#define LCD_1LINE 0x00
#define LCD_5x10DOTS 0x04
#define LCD_5x8DOTS 0x00

// Nedan följer funktioner för hantering av LCD.
void lcd_init(void);

void lcd_clear(void);

void lcd_command(uint8_t command);
void lcd_write(uint8_t value);

void lcd_on(void);
void lcd_off(void);

void lcd_return_home(void);

void lcd_enable_blinking(void);
void lcd_disable_blinking(void);

void lcd_enable_cursor(void);
void lcd_disable_cursor(void);

void lcd_scroll_left(void);
void lcd_scroll_right(void);

void lcd_enable_autoscroll(void);
void lcd_disable_autoscroll(void);

void lcd_create_char(uint8_t location, uint8_t *charmap);

void lcd_set_cursor(uint8_t col, uint8_t row);

void lcd_puts(char *string);
void lcd_printf(char *format, ...);
