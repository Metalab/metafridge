ARDUINO_TTY=/dev/ttyACM0

datarecord: datarecord.cc
	g++ -Wall -o datarecord datarecord.cc

%.elf: %.c
	avr-gcc -Wall -Os -mmcu=atmega328p -DF_CPU=16000000L -o $@ *.c

%.hex: %.elf
	avr-objcopy -j .text -j .data -O ihex $^ $@

%.prog: %.hex
	avrdude -p m328p -b 115200 -c arduino -P $(ARDUINO_TTY) -U flash:w:$^

