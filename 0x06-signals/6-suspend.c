#include "signals.h"

/**
 * signal_handler - kills self
 * @signum: the signal number
 * @siginfo: info struct about signal
 * @ucontext: pointer to ucontext_t
 */
void sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	printf("Caught %d\n", signum);
	fflush(stdout);
	(void)siginfo;
	(void)ucontext;
}

/**
 * handle_sigaction - signal handler helper using sigaction
 * Return: 0 on success else -1 on error
 */
int sig_setter(void)
{
	struct sigaction sa;

	memset(&sa, 0, sizeof(sa));
	sa.sa_flags |= SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	return (sigaction(SIGINT, &sa, NULL));
}

int main(){
	sig_setter();
    pause();
	printf("Signal received\n");
	return (EXIT_SUCCESS);
}
