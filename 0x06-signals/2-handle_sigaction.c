#include "signals.h"


/**
 * signal_handler - receives signal
 * @sig: the signal number received
 */
void signal_handler(int sig)
{
	printf("Gotcha! [%d]\n", sig);
	fflush(stdout);
}

/**
 * handle_signaction - signal handler helper using sigaction
 * Return: 0 on success else -1 on error
 */
int handle_sigaction(void)
{
	struct sigaction sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handler;
	return (sigaction(SIGINT, &sa, NULL));
}
