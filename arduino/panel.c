//panel.c
/******************************************************************************
* METAFRIDGE
******************************************************************************/

#include "panel.h"

uint8_t frame_buffer[FB_SIZE];
uint8_t panel_buffer[FB_SIZE];

inline void init_spi()
{
	PANEL_DDR  |=   (1 << PANEL_MOSI) | (1 << PANEL_SCK) | (1 << PANEL_CLEAR);
	PANEL_PORT &=~ ((1 << PANEL_MOSI) | (1 << PANEL_SCK) | (1 << PANEL_CLEAR));

	SPCR =
		(1 << SPE)  |	// Enable SPI
		(1 << MSTR) |	// We are the master
		(1 << DORD) |	// LSB first
		(1 << SPR1) |	// Clock divider...
		(1 << SPR0) ;	// ...F_CPU / 128

	// Not necessary, is disabled by default:
//	SPSR &=~ (1 << SPI2X);	// Disable double speed mode
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
	
	for( i = 0 ; i < FB_SIZE ; i++ ) {
		frame_buffer[i] = 0;
	}
}

#define LEGAL_COORDS	((x >= 0) && (x <= MAX_X) && (y >= 0) && (y <= MAX_Y))

inline void set_pixel( int16_t x, int16_t y, uint8_t value )
{
	if (LEGAL_COORDS) {
		if (value) {
			frame_buffer[x] |=  (1 << y);
		}
		else {
			frame_buffer[x] &=~ (1 << y);
		}
	}
}

inline uint8_t get_pixel( int16_t x, int16_t y )
{
	if (LEGAL_COORDS) {
		return (frame_buffer[x] & (1 << y)) ? 0xFF : 0x00 ;
	}
	else {
		return 0x00;
	}
}


inline uint8_t get_bit( uint16_t index )
{
	uint16_t x, y, p, i, imod10, f;
	
	p = index / 80;		// "Page"
	i = index - p*80;	// index % 80
	
	imod10 = i % 10;
	x = 9 - imod10;	// Counting from right to left: 1..9,
				// 0 (Blink) not in frame_buffer
	y = i / 10;		// Top to bottom:0..7
	
	f = frame_buffer[ x + p*9 ];
	
	if ( ((imod10) == 0)		// Blink Bit
	   | ((f & (1 << y)) == 0)	// Pixel not set
	) {
		return 0x00;
	}
	else {				// Pixel set
		return 0xFF;
	}
}


void shift_pixel_data()
{
	uint16_t i;

	for( i = 0 ; i < NR_PANELS*80 ;i+=8 ) {
		panel_buffer[i/8] =
			(get_bit(i + 0) & (1 << 0)) |
			(get_bit(i + 1) & (1 << 1)) |
			(get_bit(i + 2) & (1 << 2)) |
			(get_bit(i + 3) & (1 << 3)) |
			(get_bit(i + 4) & (1 << 4)) |
			(get_bit(i + 5) & (1 << 5)) |
			(get_bit(i + 6) & (1 << 6)) |
			(get_bit(i + 7) & (1 << 7)) ;
		
	}

	screen_off();
	for( i = 0 ; i < NR_PANELS*10 ; i++ ) {
		SPDR = panel_buffer[i];
		while (!(SPSR & (1 << SPIF))) /* wait */;
	}
	screen_on();
}

void scroll_left()
{
	uint8_t i, wrap;
	
	wrap = frame_buffer[0];
	
	for( i = 0 ; i < MAX_X ; i++ ) {
		frame_buffer[i] = frame_buffer[i+1];
	}
	
	frame_buffer[MAX_X] = wrap;
}

///////////////////////////////////////////////////////////////////////////////
//
//  NEW LIBRARY
//
///////////////////////////////////////////////////////////////////////////////

#define DELAY	2

void spi_send_bit( uint8_t bit )
{
	PANEL_PORT &=~ (1 << PANEL_SCK);
	_delay_us(DELAY);

	if (bit) {
		PANEL_PORT |=  (1 << PANEL_MOSI);
	}
	else {
		PANEL_PORT &=~ (1 << PANEL_MOSI);
	}

	PANEL_PORT |= (1 << PANEL_SCK);
	_delay_us(DELAY);
}

#ifdef DISABLED_CODE
void spi_send_fb()
{
	uint16_t bit_index;
	
}

void spi_send( uint8_t data )
{
#ifdef HARDWARE_SPI
	SPDR = data;
	while (!(SPSR & (1 << SPIF))) /* wait */;
#else
	uint8_t i;

	for( i = 0 ; i < 8 ; i++ ) {	
		spi_send_bit( data & (1 << i) );
	}
#endif

}
#endif

//EOF
