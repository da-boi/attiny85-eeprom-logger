#ifndef TINY_LOGGER_H
	#define TINY_LOGGER_H

	#define LOG_SIZE 512
	#define LOG_OFFSET 2
	#define LOG_P (void *)0

	/*
	 * Sets the log pointer to zero
	 * first byte is now a null character
	 * Data not actually overwritten - can still be recovered with a hex dump
	 * 		- when not overriden by log_push()
	*/
	void log_clear(void);

	/*
	 * Appends the given string to the log
	 * Terminates the log with a null character
	*/
	int log_push(const char *string);

#endif
