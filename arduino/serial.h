//serial.h
/******************************************************************************
* ATmega328 (Arduino) USART Receiver for the FRIDGEOPHANT
*******************************************************************************
* USART0 (ATmega328 Datasheet, p176)
*
* The Power Reduction USART bit, PRUSART0, in ”Minimizing Power Consumption” on
* page 42 must be disabled by writing a logical zero to it.
*
* A simplified block diagram of the USART Transmitter is shown in Figure 19-1
* on page 177.
*
* The USART Baud Rate Register (UBRRn) and the down-counter connected to it
* function as a programmable prescaler or baud rate generator. The down-
* counter, running at system clock (fosc), is loaded with the UBRRn value each
* time the counter has counted down to zero or when the UBRRnL Register is
* written. A clock is generated each time the counter reaches zero. This clock
* is the baud rate generator clock output (= fosc/(UBRRn+1)).
* The Transmitter divides the baud rate generator clock output by 2, 8 or 16
* depending on mode. The baud rate generator output is used directly by the
* Receiver’s clock and data recovery units. However, the recovery units use a
* state machine that uses 2, 8 or 16 states depending on mode set by the state
* of the UMSELn, U2Xn and DDR_XCKn bits.
*
* Table 19-1 (p179) contains equations for calculating the baud rate (in bits
* per second) and for calculating the UBRRn value for each mode of operation
* using an internally generated clock source:
*	Asynchronous Normal Mode (U2Xn = 0)
*	UBRRn = fosc / (16*BAUD) - 1
*******************************************************************************
* 19.10 REGISTER DESCRIPTION (p195)
*******************************************************************************
* UDRn - USART I/O Data Register n
* Reading the UDRn Register location will return the contents of the
* Receive Data Buffer Register (RXB)
*******************************************************************************
* UCSRnA - USART Control and Status Register n A
* Bit	7	6	5	4	3	2	1	0
*	RXCn	TXCn	UDREn	FEn	DORn	UPEn	U2Xn	MPCMn	UCSRnA
*	R	R/W	R	R	R	R	R/W	R/W
* Init	0	0	1	0	0	0	0	0
*
* Bit 7 - RXCn: USART Receive Complete
* Bit 6 - TXCn: USART Transmit Complete
* Bit 5 - UDREn: USART Data Register Empty
* Bit 4 - FEn: Frame Error
* Bit 3 - DORn: Data OverRun
* Bit 2 - UPEn: USART Parity Error
* Bit 1 - U2Xn: Double the USART Transmission Speed
* Bit 0 - MPCMn: Multi-processor Communication Mode
*/

#define USART_DOUBLE_SPEED				/* Not implemented */
#define USART_MULTI_PROCESSOR_COMMUNICATION_MODE	/* Not implemented */

/******************************************************************************
* CSRnB - USART Control and Status Register n B
* Bit	7	6	5	4	3	2	1	0
*	RXCIEn	TXCIEn	UDRIEn	RXENn	TXENn	UCSZn2	RXB8n	TXB8n	CSRnB
*	R/W	R/W	R/W	R/W	R/W	R/W	R	R/W
* Init	0	0	0	0	0	0	0	0
*
* Bit 7 - RXCIEn: RX Complete Interrupt Enable n
* Bit 6 - TXCIEn: TX Complete Interrupt Enable n
* Bit 5 - UDRIEn: USART Data Register Empty Interrupt Enable n
* Bit 4 - RXENn: Receiver Enable n
* Bit 3 - TXENn: Transmitter Enable n
* Bit 2 - UCSZn2: Character Size n
* Bit 1 - RXB8n: Receive Data Bit 8 n
* Bit 0 - TXB8n: Transmit Data Bit 8 n
*******************************************************************************
* UCSRnC - USART Control and Status Register n C
* Bit	7	6	5	4	3	2	1	0
*	UMSELn1	UMSELn0	UPMn1	UPMn0	USBSn	UCSZn1	UCSZn0	UCPOLn	UCSRnC
*	R/W	R/W	R/W	R/W	R/W	R/W	R/W	R/W
* Init	0	0	0	0	0	1	1	0
*
* Bits 7:6 - UMSELn1:0 USART Mode Select
*	UMSELn1	UMSELn0	Mode
*	0	0	Asynchronous USART
*	0	1	Synchronous USART
*	1	0	(Reserved)
*	1	1	Master SPI (MSPIM)
*/

#define USART_MODE_ASYNC	0	/* Implemented */
#define USART_MODE_SYNC		1	/* Not implemented */
#define USART_MODE_MASTER	3	/* Not implemented */

/*
* Bits 5:4 - UPMn1:0: Parity Mode
*	UPMn1	UPMn0	Mode
*	0	0	Disabled
*	0	1	(Reserved)
*	1	0	Enabled, Even Parity
*	1	1	Enabled, Odd Parity
*/

#define USART_PARITY_NONE	0
#define USART_PARITY_EVEN	2
#define USART_PARITY_ODD	3

/*
* Bit 3 - USBSn: Stop Bit Select
*	USBSn	Stop Bit(s)
*	0	1-bit
*	1	2-bit
*/

#define USART_STOPBITS_1	0
#define USART_STOPBITS_2	1

/*
* Bit 2:1 - UCSZn1:0: Character Size
*	UCSZn2	UCSZn1	UCSZn0	Character Size
*	0	0	0	5-bit
*	0	0	1	6-bit
*	0	1	0	7-bit
*	0	1	1	8-bit
*	1	0	0	(Reserved)
*	1	0	1	(Reserved)
*	1	1	0	(Reserved)
*	1	1	1	9-bit
*/

#define USART_CHARSIZE_5_BIT	0
#define USART_CHARSIZE_6_BIT	1
#define USART_CHARSIZE_7_BIT	2
#define USART_CHARSIZE_8_BIT	3
#define USART_CHARSIZE_9_BIT	7

/*
* Bit 0 - UCPOLn: Clock Polarity
*	UCPOLn	Transmitted Data Changed	Received Data Sampled
*		(Output of TxDn Pin)		(Input on RxDn Pin)
*	0	Rising XCKn Edge		Falling XCKn Edge
*	1	Falling XCKn Edge		Rising XCKn Edge
*/

#define USART_TRANSMIT_ON_RISING	0
#define USART_TRANSMIT_ON_FALLING	1

/******************************************************************************
* UBRRnL and UBRRnH - USART Baud Rate Registers
* Bit	15	14	13	12	11	10	9	8
*	-	-	-	-		UBRRn[11:8]
*				UBRRn[7:0]
* Bit	7	6	5	4	3	2	1	0
*	R	R	R	R	R/W	R/W	R/W	R/W	UBRRnH
*	R/W	R/W	R/W	R/W	R/W	R/W	R/W	R/W	UBRRnL
* Init	All 0, UBRRnH
*
* Bit 15:12 - Reserved Bits
* Bit 11:0 - UBRR11:0: USART Baud Rate Register (p199ff)
* Arduino:
*	Fcpu	UBRRn	Error	Baud Rate
*	16MHz	103	0.2%	9600
*
* The USART Baud Rate Register (UBRRn) and the down-counter connected to it
* function as a programmable prescaler or baud rate generator. The down-
* counter, running at system clock (fosc), is loaded with the UBRRn value each
* time the counter has counted down to zero or when the UBRRnL Register is
* written. A clock is generated each time the counter reaches zero. This clock
* is the baud rate generator clock output (= fosc/(UBRRn+1)). The Transmitter
* divides the baud rate generator clock output by 2, 8 or 16 depending on mode.
* The baud rate generator output is used directly by the Receiver’s clock and
* data recovery units. However, the recovery units use a state machine that
* uses 2, 8 or 16 states depending on mode set by the state of the UMSELn, U2Xn
* and DDR_XCKn bits.
******************************************************************************/

inline void USART_init(	uint16_t baud_rate,
			uint8_t  char_size,
			uint8_t  parity,
			uint8_t  stop_bits
		);

unsigned char USART_Receive( void );

//EOF
