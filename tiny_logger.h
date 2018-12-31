#ifndef TINY_LOGGER_H
	#define TINY_LOGGER_H

	#define LOG_SIZE 512
	#define LOG_OFFSET 2
	#define LOG_P (void *)0

	void log_clear(void);
	int log_push(const char *string);

#endif
