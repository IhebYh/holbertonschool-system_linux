#include "multithreading.h"

/**
 * tprintf - a function that uses the
 * printf family to print out a given formatted string
 * @format: format of the text given
 * @...: other given params
 * Return: int
 */

int tprintf(char const *format, ...)
{
	pthread_t current_thread = pthread_self();
	va_list arg;
	int done;

	va_start(arg, format);
	printf("[%lu] ", current_thread);
	done = vfprintf(stdout, format, arg);
	va_end(arg);
	return (done);
}
