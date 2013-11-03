//main.c
/******************************************************************************
* METAFRIDGE
******************************************************************************/

#include "main.h"

// INITIALIZATION /////////////////////////////////////////////////////////////


inline void init()
{
	USART_init(
		9600,	/* BAUD */
		USART_CHARSIZE_8_BIT,
		USART_PARITY_NONE,
		USART_STOPBITS_1
	);
	sei();			// Enable global interrupts
}


// RESET //////////////////////////////////////////////////////////////////////

uint16_t crsr_x = 0;

void print_char( uint8_t ascii_code )	
{
	crsr_x += show_ascii_xy( ascii_code, crsr_x, 0 );
	//crsr_x %= MAX_X;
}

void print_string( int16_t offset_x, char* text )
{
	register char c;
	
	crsr_x = offset_x;
	
	while( (c = *text++) ) {
		print_char( c );
	}
}


#define TEST_STRING	"Metafridge "		\
			"!\"#$%&'()*+,-./0123456789"	\
			":;<=>?@"			\
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"	\
			"[\\]^_`"			\
			"abcdefghijklmnopqrstuvwxyz"	\
			"{|}~"

#define SCROLL_WIDTH	(470 + SPACE_BETWEEN_CHARS*90)
void test()
{
	static int16_t x = NR_PANELS * 9;
	print_string( x--, TEST_STRING );

	if (x < -SCROLL_WIDTH) {
		x =  NR_PANELS * 9;
	}
}

int main(void)
{
	uint8_t counter = 0;
	
	init();
	
	while (1) {
		//scroll_title_map();
		if (++counter == COUNTER_DELAY) {
			clear_frame_buffer();
			test();
			counter = 0;
		}
		shift_pixel_data();
		//_delay_ms(1);
	}
	
	return 0;		// Never reached, but prevents warning.
}

//EOF
