#include "signals.h"

/**
 * current_handler_sigaction - retrieves handler by sigaction
 * Return: current handler or NULL
 */

void (*current_handler_sigaction(void))(int)
{
	struct sigaction oldact;

	memset(&oldact, 0, sizeof(oldact));
	return (sigaction(SIGINT, NULL, &oldact) ? NULL : oldact.sa_handler);
}
