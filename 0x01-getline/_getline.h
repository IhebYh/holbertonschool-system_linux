#ifndef _GETLINE_H_
#define _GETLINE_H_

/******* Libraries ********/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/******* Macros ********/
#define READ_SIZE 1024

/******** Structs *********/
/**
 * struct fd_s - linked list for file descriptor.
 * @fd: The file descriptor .
 * @buffer: The buffer associated to fd.
 * @data: data
 * @next: The pointer to the next node
 */
typedef struct fd_s
{
	int fd;
	char *buffer;
	int data;
	struct fd_s *next;
} fd_t;

/******** Functions ********/
char *_getline(const int fd);
void _free(fd_t *scan, fd_t *getline);
char *line_parser(fd_t *scanner);
#endif /* _GETLINE_H_ */
