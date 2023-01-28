#ifndef _STRACE_H_
#define _STRACE_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ptrace.h>
#include <sys/wait.h>
#include <x86_64-linux-gnu/sys/user.h>
#include <unistd.h>

#include "syscalls.h"

extern char **environ;
void trace_child(char **av, char **envp);
void trace_parent(pid_t child_pid);
int await_syscall(pid_t child_pid);

#endif /* _STRACE_H_ */