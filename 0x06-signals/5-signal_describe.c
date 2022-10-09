#include "signals.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Success or Failure
 */

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <signum>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (strsignal(atoi(argv[1])))
		printf("%d: %s\n", atoi(argv[1]), strsignal(atoi(argv[1])));
	else
		printf("%d Unknown signal %d\n", atoi(argv[1]), atoi(argv[1]));
	return (EXIT_SUCCESS);
}
