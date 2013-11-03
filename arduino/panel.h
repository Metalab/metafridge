//panel.h
/******************************************************************************
* METAFRIDGE
*******************************************************************************
* PANEL, TOP VIEW:
*    .--------------------------------------------------------------------.
*    |                                                                    |
*    |                                                                    |
*    |                                                                    |
*   1<                                                                    >1
*    |                                                                    |
*   2<                                                                    >2
*    |                                                                    |
*   3<                                                                    >3
*    |                                                                    |
*   4<SCK                                                                 >4
*    |                                                                    |
*   5<                                                                    >5
*    |                                                                    |
*   6<                                                                    >6
*    |      ##       ##       ##       ##       ##       ##       ##      |
*    |      ##       ##       ##       ##       ##       ##       ##      |
*    |      ##       ##       ##       ##       ##       ##       ##      |
*   7<                                                                    >7
*    |                                                                    |
*   8<MOSI  ##       ##       ##       ##                         ##      >8
*    |      ##       ##       ##       ##                         ##      |
*   9<      ##       ##       ##       ##                         ##      >9
*    |      ##                         ##                                 |
*  10<CLEAR                                                               >10
*    |                                                                    |
*  5V<                                                                    >5V
*    |                                                                    |
*  8V<                                                                    >8V
*    |                                                                    |
* GND<                                                                    >GND
*    |                                                                    |
* 12V<                                                                    >12V
*    '--------------------------------------------------------------------'
*
* Connect SCK, MOSI and CLEAR according to the defines below. Also connect GND!
******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>

#define PANEL_DDR	DDRB
#define PANEL_PORT	PORTB
#define PANEL_CLEAR	2	// Arduino-pin 10
#define PANEL_MOSI	PB3	// Arduino-pin 11
#define PANEL_SCK	PB5	// Arduino-pin 13

#define NR_PANELS	4
#define MAX_X		(NR_PANELS*9-1)
#define MAX_Y		7
#define FB_SIZE		(9*NR_PANELS)	/* 1 Column BLINK, 9 Cols. Pixels */

#define HARDWARE_SPI


uint8_t frame_buffer[FB_SIZE];

inline void init_spi();

inline void screen_off();
inline void screen_on();

void clear_frame_buffer();

void set_pixel( int16_t x, int16_t y, uint8_t value );
uint8_t get_pixel( int16_t x, int16_t y );

void shift_pixel_data();

void scroll_left();

//EOF
