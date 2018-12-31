#include <avr/io.h>

#include "tiny_logger.h"


int main(void) {
	const char *s0 = "Nice brah, you did it";
	log_clear();
	log_push(s0);
}
