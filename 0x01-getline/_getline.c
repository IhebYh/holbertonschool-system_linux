#include "_getline.h"

/**
 * _getline - reads an entire line from a file descriptor
 * @fd: file descriptor
 * Return: string without empty string at the eof
 */

char *_getline(const int fd)
{
	static fd_t *getline;
	fd_t *scanner = NULL;
	char *buffer = NULL;
	int data;

	if (fd == -1)
	{
		free(buffer);
		_free(scanner, getline);
		return (NULL);
	}
	for (scanner = getline; scanner; scanner = scanner->next)
		if (scanner->fd == fd)
		{
			if (scanner->data <= 0)
				scanner->data = read(fd, scanner->buffer, READ_SIZE);
			return (line_parser(scanner));
		}
	buffer = malloc(sizeof(char) * READ_SIZE);
	if (buffer == NULL)
		return (NULL);
	data = read(fd, buffer, READ_SIZE);
	if (data <= 0)
	{
		free(buffer);
		_free(scanner, getline);
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
/**
 * _free - free vars when fd == -1
 * @scan: file descriptor
 * @getline: file descriptor
 * Return: void
 */
void _free(fd_t *scan, fd_t *getline)
{
	fd_t *temp = NULL;

	if (getline->buffer)
	{
		free(getline->buffer);
		getline->buffer = NULL;
	}
	for (scan = getline->next; scan;)
	{
		if (scan->buffer)
		{
			free(scan->buffer);
			scan->buffer = NULL;
		}
		temp = scan;
		scan = scan->next;
		free(temp);
	}
	getline->next = NULL;
}
/**
 * line_parser - parse, split and handle lines
 * @scan : pointer to scanned data
 * Return: pointer to the parsed line
 */
char *line_parser(fd_t *scan)
{
	int i, j;
	int size = 0;
	int data = 0;
	char *line = NULL, *tmp;

	while (scan->data > 0)
	{
		if (size < data + scan->data + 1)
		{
			size += scan->data + 1;
			tmp = malloc(sizeof(char) * size);
			if (tmp == NULL)
			{
				free(line);
				return (NULL);
			}
			memcpy(tmp, line, data);
			memset(tmp + data, '\0', size - data);
			free(line);
			line = tmp;
		}
		for (i = 0; i < scan->data; i++)
			if (scan->buffer[i] == '\n')
			{
				scan->buffer[i++] = '\0';
				scan->data -= i;
				memcpy(line + data, scan->buffer, i);
				for (j = 0; i < READ_SIZE; j++, i++)
					scan->buffer[j] = scan->buffer[i];
				for (; j < READ_SIZE; j++)
					scan->buffer[j] = '\0';
				return (line);
			}
		memcpy(line + data, scan->buffer, scan->data);
		data += scan->data;
		scan->data = read(scan->fd, scan->buffer, READ_SIZE);
	}
	return (line);
}
