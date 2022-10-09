#include "signals.h"

/**
 * signal_handler - receives signal
 * @sig: the signal number received
 */
void signal_handler(int sig)
{
	printf("SIGQUIT sent by %d\n", sig);
	fflush(stdout);
}

/**
 * trace_signal_sender - a handler of SIGQUIT
 * Return: 0 or -1
 */
int trace_signal_sender(void)
{
	struct sigaction sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = signal_handler;
	return (sigaction(SIGQUIT, &sa, NULL));
}
