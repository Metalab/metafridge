/******************************************************************************
* BLINKOFANT template controller for the Arduino
* https://metalab.at/wiki/Blinkofant
* https://metalab.at/wiki/Datei:Ledmatrix_chained.png
*******************************************************************************
* ATmega328p datasheet:
*	Table 18-5. Relationship Between SCK and the Oscillator Frequency
*	SPI2X	SPR1	SPR0	SCK Frequency
*	0	0	0	fosc/4
*	0	0	1	fosc/16
*	0	1	0	fosc/64
*	0	1	1	fosc/128  <-- We need to be really sluggish
*	1	0	0	fosc/2
*	1	0	1	fosc/8
*	1	1	0	fosc/32
*	1	1	1	fosc/64
*******************************************************************************
* Data and clock lines must be PB3 and PB5 respectively, if we want to use
* hardware SPI.
******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>

#define PANEL_DDR	DDRB
#define PANEL_PORT	PORTB
#define PANEL_CLEAR	2	// Arduino-pin 10
#define PANEL_MOSI	PB3	// Arduino-pin 11
#define PANEL_SCK	PB5	// Arduino-pin 13

#define PANELS		1
#define PANEL_DATA_SIZE	(10*PANELS)

uint8_t panel_data[PANEL_DATA_SIZE];

void init()
{
	PANEL_DDR  |=   (1 << PANEL_MOSI) | (1 << PANEL_SCK) | (1 << PANEL_CLEAR);
	PANEL_PORT &=~ ((1 << PANEL_MOSI) | (1 << PANEL_SCK) | (1 << PANEL_CLEAR));

	SPCR =	(1 << SPE)  |	// Enable SPI
		(1 << MSTR) |	// We are the master
		(1 << DORD) |	// LSB first
		(1 << SPR1) |	// Clock divider...
		(1 << SPR0) ;	// ...F_CPU / 128

	// Not necessary, is disabled by default:
	// SPSR &=~ (1 << SPI2X);	// Disable double speed mode
}

inline void screen_off()
{
	PANEL_PORT &=~ (1 << PANEL_CLEAR);
}

inline void screen_on()
{
	PANEL_PORT |=  (1 << PANEL_CLEAR);
}

void clear_frame_buffer()
{
	uint8_t i;
	
	for( i = 0 ; i < PANEL_DATA_SIZE ; i++ ) {
		panel_data[i] = 0x00;
	}
}

void set_pixel( uint8_t x, uint8_t y, uint8_t value )
{
	uint8_t index   = (x*10) + (y+1);	// y+1 because first bit controls blinking
	uint8_t byte_nr = index >> 3;		// Division by 8
	uint8_t bit_nr  = index & 0b00000111;	// Remainder of division

	if (value) {
		panel_data[byte_nr] |=  (1 << bit_nr);
	}
	else {
		panel_data[byte_nr] &=~ (1 << bit_nr);
	}
}

void shift_pixel_data()
{
	uint8_t i;

	screen_off();

	for ( i = 0 ; i < PANEL_DATA_SIZE ; i++ ) {
		SPDR = panel_data[i];
		while (!(SPSR & (1 << SPIF))) /* wait */;
	}

	screen_on();
}

int main(void)
{
	uint8_t state = 0;

	init();

	while(1) {
		state++;

		clear_frame_buffer();
		
		set_pixel( state % 64, 2, 1 );

		shift_pixel_data();

		_delay_ms(500);
	}
}
