#include "signals.h"

/**
 * current_handler_signal - returns current handler
 * Return: the current SIGINT handler
 */

void (*current_handler_signal(void))(int){
	sighandler_t sig_handler;

	sig_handler = signal(SIGINT, SIG_DFL);
	if (sig_handler == SIG_ERR)
		return (NULL);

	return (signal(SIGINT, sig_handler) == SIG_ERR ? NULL : sig_handler);
}
