.PHONY: clean
compile:
	avr-gcc -mmcu=attiny85 -Wall -Os -o blink.elf blink.c

.PHONY: build
build:
	avr-objcopy -j .text -j .data -O ihex blink.elf blink.hex

.PHONY: load
load:
	avrdude -p t85 -c usbtiny -e -U flash:w:blink.hex -U lfuse:w:0x82:m -v

.PHONY: clean
clean:
	rm -f *.o *.elf *.hex


