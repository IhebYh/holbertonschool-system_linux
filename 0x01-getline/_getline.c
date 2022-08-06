#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor
 * Return: string without empty string at the eof
 */

char *_getline(const int fd)
{
	static fd_t *getline;
	fd_t *scanner;
	char *buffer;
	int data;

	for (scanner = getline; scanner; scanner = scanner->next)
		if (scanner->fd == fd)
		{
			if (scanner->data <= 0)
				scanner->data = read(fd, scanner->buffer, READ_SIZE);
			return (line_parser(scanner));
		}
	buffer = malloc(sizeof(char) * READ_SIZE);
	data = read(fd, buffer, READ_SIZE);
	if (data <= 0)
	{
		free(info);
		return (NULL);
	}
	scanner = malloc(sizeof(fd_t));
	if (scanner == NULL)
		return (NULL);
	scanner->fd = fd;
	scanner->buffer = buffer;
	scanner->data = data;
	scanner->next = getline;
	getline = scanner;
	return (line_parser(scanner));
}
