#include "multithreading.h"

/**
 * thread_entry - Write a function that will serve as the entry
 * point to a new thread.
 * @arg: holds the address of a string that must be printed
 * Return: void*
 */
void *thread_entry(void *arg)
{
	char *data = (char *) arg;

	printf("%s\n", data);
	pthread_exit(NULL);
}
