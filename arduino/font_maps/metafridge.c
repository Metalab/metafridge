//font_maps.h
/******************************************************************************
* METAFRIDGE FONT UTILS - Easy font editing defines
******************************************************************************/

#include "../font.h"

const uint8_t ascii_maps[][7] PROGMEM = {
	{	I________,	// 32 ' '
		I________,
		I________,
		I________,
		I________,
	},
	{	I_x_xxxxx,	// 33 '!'
	},
	{	I______xx,	// 34 '"'
		I________,
		I______xx,
	},
	{	I__x__x__,	// 35 '#'
		I_xxxxxx_,
		I__x__x__,
		I__x__x__,
		I_xxxxxx_,
		I__x__x__,
	},
	{	I__x__x__,	// 36 '$'
		I__x_x_x_,
		I_xxxxxxx,
		I__x_x_x_,
		I___x__x_,
	},
	{	I_x____x_,	// 37 '%'
		I__x__x_x,
		I___x__x_,
		I____x___,
		I__x__x__,
		I_x_x__x_,
		I__x____x,
	},
	{	I__xx_xx_,	// 38 '&'
		I_x__x__x,
		I_x__x__x,
		I__xx_x__,
		I_x______,
	},
	{	I_____x__,	// 39  '
		I______xx,
	},
	{	I___xxx__,	// 40 '('
		I__x___x_,
		I_x_____x,
	},
	{	I_x_____x,	// 41 ')'
		I__x___x_,
		I___xxx__,
	},
	{	I____x___,	// 42 '*'
		I_x__x__x,
		I__x_x_x_,
		I___xxx__,
		I__x_x_x_,
		I_x__x__x,
		I____x___,
	},
	{	I____x___,	// 43 '+'
		I____x___,
		I__xxxxx_,
		I____x___,
		I____x___,
	},
	{	Ix_______,	// 44 ','
		I_xx_____,
	},
	{	I____x___,	// 45 '-'
		I____x___,
		I____x___,
		I____x___,
	},
	{	I_x______,	// 46 '.'
	},
	{	I_xx_____,	// 47 '/'
		I___x____,
		I____x___,
		I_____x__,
		I______xx,
	},
	{	I__xxxxx_,	// 48 '0'
		I_xx____x,
		I_x_____x,
		I_x____xx,
		I__xxxxx_,
	},
	{	I_x____x_,	// 49 '1'
		I_xxxxxxx,
		I_x______,
	},
	{	I_xxx__x_,	// 50 '2'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I_xx__xx_,
	},
	{	I__x___x_,	// 51 '3'
		I_x_____x,
		I_x__x__x,
		I_x__x__x,
		I__xx_xx_,
	},
	{	I___xx___,	// 52 '4'
		I___x_x__,
		I___x__x_,
		I_xxxxxxx,
		I___x____,
	},
	{	I__x__xxx,	// 53 '5'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I__xx__xx,
	},
	{	I__xxxxx_,	// 54 '6'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I__xx__x_,
	},
	{	I______xx,	// 55 '7'
		I_______x,
		I_xxx___x,
		I____xx_x,
		I______xx,
	},
	{	I__xx_xx_,	// 56 '8'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I__xx_xx_,
	},
	{	I__x__xx_,	// 57 '9'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I__xxxxx_,
	},
	{	I__x__x__,	// 58 ':'
	},
	{	Ix_______,	// 59 ';'
		I_xx__x__,
	},
	{	I____x___,	// 60 '<'
		I___x_x__,
		I__x___x_,
		I_x_____x,
	},
	{	I___x_x__,	// 61 '='
		I___x_x__,
		I___x_x__,
	},
	{	I_x_____x,	// 62 '>'
		I__x___x_,
		I___x_x__,
		I____x___,
	},
	{	I______x_,	// 63 '?'
		I_______x,
		I_x_x___x,
		I____x__x,
		I_____xx_,
	},
	{	I__xxxxx_,	// 64 '@'
		I_x_____x,
		I_x_xxx_x,
		I_x_xxx_x,
		I_x_xxxx_,
	},
	{	I_xxxxx__,	// 65 'A'
		I___x__x_,
		I___x___x,
		I___x__x_,
		I_xxxxx__,
	},
	{	I_xxxxxxx,	// 66 'B'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I__xx_xx_,
	},
	{	I__xxxxx_,	// 67 'C'
		I_x_____x,
		I_x_____x,
		I_x_____x,
		I__x___x_,
	},
	{	I_xxxxxxx,	// 68 'D'
		I_x_____x,
		I_x_____x,
		I__x___x_,
		I___xxx__,
	},
	{	I_xxxxxxx,	// 69 'E'
		I_x__x__x,
		I_x__x__x,
		I_x_____x,
	},
	{	I_xxxxxxx,	// 70 'F'
		I____x__x,
		I____x__x,
		I_______x,
	},
	{	I__xxxxx_,	// 71 'G'
		I_x_____x,
		I_x_____x,
		I_x__x__x,
		I__xxx_x_,
	},
	{	I_xxxxxxx,	// 72 'H'
		I____x___,
		I____x___,
		I____x___,
		I_xxxxxxx,
	},
	{	I_x_____x,	// 73 'I'
		I_xxxxxxx,
		I_x_____x,
	},
	{	I__x___xx,	// 74 'J'
		I_x_____x,
		I_x_____x,
		I__xxxxxx,
	},
	{	I_xxxxxxx,	// 75 'K'
		I____x___,
		I___x_x__,
		I__x___x_,
		I_x_____x,
	},
	{	I_xxxxxxx,	// 76 'L'
		I_x______,
		I_x______,
		I_x______,
	},
	{	I_xxxxxxx,	// 77 'M'
		I______x_,
		I_____x__,
		I___xx___,
		I_____x__,
		I______x_,
		I_xxxxxxx,
	},
	{	I_xxxxxxx,	// 78 'N'
		I______x_,
		I_____x__,
		I____x___,
		I___x____,
		I_xxxxxxx,
	},
	{	I__xxxxx_,	// 79 'O'
		I_x_____x,
		I_x_____x,
		I_x_____x,
		I__xxxxx_,
	},
	{	I_xxxxxxx,	// 80 'P'
		I____x__x,
		I____x__x,
		I____x__x,
		I_____xx_,
	},
	{	I__xxxxx_,	// 81 'Q'
		I_x_____x,
		I_x_____x,
		I__x____x,
		I_x_xxxx_,
	},
	{	I_xxxxxxx,	// 82 'R'
		I____x__x,
		I____x__x,
		I___xx__x,
		I_xx__xx_,
	},
	{	I__x__xx_,	// 83 'S'
		I_x__x__x,
		I_x__x__x,
		I_x__x__x,
		I__xx__x_,
	},
	{	I_______x,	// 84 'T'
		I_______x,
		I_xxxxxxx,
		I_______x,
		I_______x,
	},
	{	I__xxxxxx,	// 85 'U'
		I_x______,
		I_x______,
		I_x______,
		I__xxxxxx,
	},
	{	I_____xxx,	// 86 'V'
		I___xx___,
		I_xx_____,
		I___xx___,
		I_____xxx,
	},
	{	I__xxxxxx,	// 87 'W'
		I_x______,
		I__x_____,
		I___xx___,
		I__x_____,
		I_x______,
		I__xxxxxx,
	},
	{	I_xx___xx,	// 88 'X'
		I___x_x__,
		I____x___,
		I___x_x__,
		I_xx___xx,
	},
	{	I_____xxx,	// 89 'Y'
		I____x___,
		I_xxx____,
		I____x___,
		I_____xxx,
	},
	{	I_xx____x,	// 90 'Z'
		I_x_xx__x,
		I_x__xx_x,
		I_x____xx,
	},
	{	I_xxxxxxx,	// 91 '['
		I_x_____x,
	},
	{	I______xx,	// 92 '\'
		I_____x__,
		I____x___,
		I___x____,
		I_xx_____,
	},
	{	I_x_____x,	// 93 ']'
		I_xxxxxxx,
	},
	{	I______x_,	// 94 '^'
		I_______x,
		I______x_,
	},
	{	Ix_______,	// 95 '_'
		Ix_______,
		Ix_______,
		Ix_______,
	},
	{	I_______x,	// 96 '`'
		I______x_,
	},
	{	I__x_____,	// 97 'a'
		I_x_x_x__,
		I_x_x_x__,
		I_xxxx___,
	},
	{	I_xxxxxxx,	// 98 'b'
		I_x___x__,
		I_x___x__,
		I__xxx___,
	},
	{	I__xxx___,	// 99 'c'
		I_x___x__,
		I_x___x__,
		I__x_x___,
	},
	{	I__xxx___,	// 100 'd'
		I_x___x__,
		I_x___x__,
		I_xxxxxxx,
	},
	{	I__xxx___,	// 101 'e'
		I_x_x_x__,
		I_x_x_x__,
		I_x_xx___,
	},
	{	I_____x__,	// 102 'f'
		I_xxxxxx_,
		I_____x_x,
	},
	{	I___xx___,	// 103 'g'
		Ix_x__x__,
		Ix_x__x__,
		I_xxxxx__,
	},
	{	I_xxxxxxx,	// 104 'h'
		I_____x__,
		I_____x__,
		I_xxxx___,
	},
	{	I_x___x__,	// 105 'i'
		I_xxxxx_x,
		I_x______,
	},
	{	Ix____x__,	// 106 'j'
		I_xxxxx_x,
	},
	{	I_xxxxxxx,	// 107 'k'
		I___x____,
		I__x_x___,
		I_x___x__,
		I________,
	},
	{	I__xxxxxx,	// 108 'l'
		I_x______,
	},
	{	I_xxxxx__,	// 109 'm'
		I_____x__,
		I_____x__,
		I_xxxx___,
		I_____x__,
		I_____x__,
		I_xxxx___,
	},
	{	I_xxxxx__,	// 110 'n'
		I_____x__,
		I_____x__,
		I_xxxx___,
	},
	{	I__xxx___,	// 111 'o'
		I_x___x__,
		I_x___x__,
		I__xxx___,
	},
	{	Ixxxxxx__,	// 112 'p'
		I__x__x__,
		I__x__x__,
		I___xx___,
	},
	{	I___xx___,	// 113 'q'
		I__x__x__,
		I__x__x__,
		Ixxxxxx__,
		I________,
		I________,
	},
	{	I_xxxxx__,	// 114 'r'
		I_____x__,
		I____x___,
	},
	{	I_x_xx___,	// 115 's'
		I_x_x_x__,
		I_x_x_x__,
		I__xx_x__,
	},
	{	I______x_,	// 116 't'
		I__xxxxxx,
		I_x____x_,
	},
	{	I__xxxx__,	// 117 'u'
		I_x______,
		I_x______,
		I_xxxxx__,
	},
	{	I___xxx__,	// 118 'v'
		I__x_____,
		I_x______,
		I__x_____,
		I___xxx__,
	},
	{	I__xxxx__,	// 119 'w'
		I_x______,
		I__xx____,
		I_x______,
		I__xxxx__,
	},
	{	I_x___x__,	// 120 'x'
		I__x_x___,
		I___x____,
		I__x_x___,
		I_x___x__,
	},
	{	I___xxx__,	// 121 'y'
		Ix_x_____,
		Ix_x_____,
		I_xxxxx__,
	},
	{	I_xx__x__,	// 122 'z'
		I_x_x_x__,
		I_x_x_x__,
		I_x__xx__,
	},
	{	I____x___,	// 123 '{'
		I__xx_xx_,
		I_x_____x,
	},
	{	I_xxx_xxx,	// 124 '|'
	},
	{	I_x_____x,	// 125 '}'
		I__xx_xx_,
		I____x___,
	},
	{	I_____x__,	// 126 '~'
		I______x_,
		I______x_,
		I_____x__,
		I____x___,
		I____x___,
		I_____x__,
	}
};

//EOF
