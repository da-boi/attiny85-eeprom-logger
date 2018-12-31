#include <avr/io.h>
#include <string.h>
#include <avr/eeprom.h>

#include "tiny_logger.h"

void log_clear(void) {
	/* 
	 * Set the log pointer to the log offset
	 * effectively clearing the log by allowing override
	*/
	eeprom_update_word(LOG_P, LOG_OFFSET);

	/* Write a null char into the first log byte */
	eeprom_update_byte((uint8_t *)LOG_OFFSET, '\0');
}

int log_push(const char* string) {
	size_t size;
	void *addr;

	size = strlen(string);
	addr = (void *)eeprom_read_word(LOG_P);

	if ( (addr + size) > (void *)(LOG_SIZE - LOG_OFFSET) ) {
		return -1;
	}

	eeprom_update_block(string, addr, size);
	addr += size;
	eeprom_update_byte(addr, '\0');
	eeprom_update_word(LOG_P, (uint16_t)addr);
	return 0;
}
