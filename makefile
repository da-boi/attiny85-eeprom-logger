prog: tiny_logger.hex
	avrdude -c avrispv2 -P /dev/ttyACM0 -p t85 -U flash:w:tiny_logger.hex -v

main.o: main.c
	avr-gcc -Os -mmcu=attiny85 -c -o main.o main.c

tiny_logger.o: tiny_logger.c tiny_logger.h
	avr-gcc -Os -mmcu=attiny85 -c -o tiny_logger.o tiny_logger.c

tiny_logger.elf: main.o tiny_logger.o
	avr-gcc -mmcu=attiny85 -o tiny_logger.elf main.o tiny_logger.o

tiny_logger.hex: tiny_logger.elf
	avr-objcopy -j .text -j .data -O ihex tiny_logger.elf tiny_logger.hex
