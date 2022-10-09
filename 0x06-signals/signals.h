#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int handle_signal(void);
void signal_handler(int sig);

#endif /* _SIGNALS_H_ */
