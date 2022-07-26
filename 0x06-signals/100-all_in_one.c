#include "signals.h"

/**
 * sigaction_handler - act as handler for sigaction syscall
 * @signum: an integer representing a signal
 * @info: a pointer to a siginfo_t with info about the signal
 * @ucontext: a void pointer to a user context (getcontext(3))
 * Return: Always void
 */
void sigaction_handler(__attribute__((unused))int signum,
siginfo_t *info, __attribute__((unused))void *ucontext)
{
	char *msg = "Caught";

	psiginfo(info, msg);
	fflush(stdout);
}

/**
 * all_in_one - it sets up a single handler for all the signals
 * Return: Always void
 */
void all_in_one(void)
{
	int i;
	struct sigaction action;

	action.sa_sigaction = sigaction_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags |= SA_SIGINFO;
	for (i = 1; i < _NSIG; i++)
		sigaction(i, &action, NULL);
}
