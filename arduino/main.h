//main.h
/******************************************************************************
* METAFRIDGE
*******************************************************************************
* https://metalab.at/wiki/Blinkofant
* https://metalab.at/wiki/Datei:Ledmatrix_chained.png
* https://metalab.at/wiki/Fonera
*******************************************************************************
* TODO
*	- Read back current text
*	- Notifications: interrupting normal text and switching back to it
*	- Notifications: Duration/Iterations
*	- RT Clock
*	- Progress bar (Event time info/Countdown/Pauses)
*	- Inverted Font
*	- Euro sign
*	- Kerning
*	- Screen saver
*	- Power saving unit with motion detector
*******************************************************************************
* FONERA, top view:
*         .-------------------------.
*         |                         |
* Antenna <                         |
*         |                      ####
*         |                      ####
*         |                         |
*         |             1234      ###
*         |             oooo      ###
*         '-------------------------'
*           2: TX
*           3: RX
*           4: GND
******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <util/delay.h>
#include "serial.h"
#include "panel.h"
#include "font.h"

//EOF
