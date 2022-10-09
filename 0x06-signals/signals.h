#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

int handle_signal(void);
void signal_handler(int sig);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);
int trace_signal_sender(void);
int sig_setter(void);
void sig_handler(int signum, siginfo_t *siginfo, void *ucontext);

#endif /* _SIGNALS_H_ */
