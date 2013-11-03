//serial.c
/******************************************************************************
* ATmega328 (Arduino) USART Receiver for the FRIDGEOPHANT
******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"

inline void USART_init(	uint16_t baud_rate,
			uint8_t  char_size,
			uint8_t  parity,
			uint8_t  stop_bits
		)
{
	uint8_t char_size_2 = ((char_size & 4) != 0);
	uint8_t char_size_1 = ((char_size & 2) != 0);
	uint8_t char_size_0 = ((char_size & 1) != 0);
	
	uint8_t parity_1 = ((parity & 2) != 0);
	uint8_t parity_0 = ((parity & 1) != 0);

	uint8_t sreg_save = SREG;	/* Save interrupts enable bit */
	cli();				/* Disable global interrupts */


	/* The Power Reduction USART bit, PRUSART0, in "Minimizing Power
	 * Consumption" on page 42 must be disabled by writing a logical
	 * zero to it.
	 */
	 
	//...
	

	/* UCSRnA - USART Control and Status Register n A
	 * Bit 7 - RXCn:  USART Receive Complete
	 * Bit 6 - TXCn:  USART Transmit Complete
	 * Bit 5 - UDREn: USART Data Register Empty
	 * Bit 4 - FEn:   Frame Error
	 * Bit 3 - DORn:  Data OverRun
	 * Bit 2 - UPEn:  USART Parity Error
	 * Bit 1 - U2Xn:  Double the USART Transmission Speed
	 * Bit 0 - MPCMn: Multi-processor Communication Mode
	 */
	UCSR0A &= ~((1 << U2X0) | (1 << MPCM0));	/* Not implemented  */
	
	/* UCSRnA - USART Control and Status Register n B */
	UCSR0B =
		(1 << RXCIE0) |          /* 7 RX Complete Interrupt Enable n */
		(0 << TXCIE0) |	         /* 6 TX Complete Interrupt Enable n */
		(0 << UDRIE0) |	 /* 5 Data Register Empty Interrupt Enable n */
		(1 << RXEN0)  |	           /* 4  Receiver Enable n           */
		(0 << TXEN0)  |	           /* 3  Transmitter Enable n        */
		(char_size_2 << UCSZ02);   /* 2 Character Size n             */
				           /* 1 RXB8n: Receive Data Bit 8 n  */
				           /* 0 TXB8n: Transmit Data Bit 8 n */
				
	/* UCSRnA - USART Control and Status Register n C */
	UCSR0C =
		(0 << UMSEL01) |	  /* 7:6 USART Mode Select        */
		(0 << UMSEL00) |
		(parity_1 << UPM01)  |	  /* 5:4 Parity Mode              */
		(parity_0 << UPM00)  |
		(stop_bits << USBS0)  |	  /* 3   Stop Bit Select          */
		(char_size_1 << UCSZ01) | /* 2:1 UCSZn1:0: Character Size */
		(char_size_0 << UCSZ00) |
		(0 << UCPOL0)  ;          /* 0    Clock Polarity          */

	/* Set BAUD rate */
	uint8_t new_UBBRn = F_CPU / (baud_rate * 16) - 1;
	UBRR0H = (new_UBBRn >> 8);
	UBRR0L = (new_UBBRn & 0xFF);
	
	/* Re-enable global interrupts, if they were enabled before */
	SREG = sreg_save;
}

#define UCSRnA	UCSR0A
#define RXCn	RXC0
#define TXCn	TXC0
#define UDRn	UDR0

unsigned char USART_Receive( void )
{
	/* Wait for data to be received */
	while ( !(UCSRnA & (1<<RXCn)) ) ;
	
	/* Get and return received data from buffer */
	return UDRn;
}

//EOF
