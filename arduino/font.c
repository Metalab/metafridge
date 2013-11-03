//font.c
/******************************************************************************
* METAFRIDGE FONT UTILS
******************************************************************************/

#include <avr/pgmspace.h>
#include <util/delay.h>
#include "font.h"
#include "main.h"
#include "panel.h"

#include "font_maps/metafridge.c"

///////////////////////////////////////////////////////////////////////////////

uint8_t temp_ascii_map[MAX_CHAR_WIDTH];

///////////////////////////////////////////////////////////////////////////////

void get_temp_ascii_map( uint8_t ascii_code )
{
	uint8_t i;
	
	for( i = 0 ; i < MAX_CHAR_WIDTH ; i++ ) {
		temp_ascii_map[i] = pgm_read_byte( &ascii_maps[ascii_code - 32][0] + i );
	}
}

uint16_t show_ascii_xy( uint8_t ascii_code, int16_t offset_x, int16_t offset_y )
{
	uint8_t char_width = 0;
	uint8_t col_map = 0;
	uint8_t column, row;

	if (ascii_code == 32) {
		char_width = SPACE_CHAR_WIDTH;
	}
	else {
		get_temp_ascii_map( ascii_code );

		for( column = 0 ; column < MAX_CHAR_WIDTH ; column++ ) {
			col_map = temp_ascii_map[column];
			for( row = 0 ; row <= MAX_Y ; row++ ) {
				set_pixel(
					offset_x + column,
					offset_y + row,
					col_map & (1 << row)
				);
			}
			char_width += (col_map > 0);
		}
	
		if (ascii_code == 34) char_width++;
	}
	
	return char_width + SPACE_BETWEEN_CHARS;
}

//EOF
