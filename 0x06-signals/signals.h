#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int handle_signal(void);
void signal_handler(int sig);
void (*current_handler_signal(void))(int);
int handle_sigaction(void);
void (*current_handler_sigaction(void))(int);

#endif /* _SIGNALS_H_ */
