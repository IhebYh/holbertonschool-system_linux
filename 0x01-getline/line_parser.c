#include "_getline.h"

/**
 * line_parser - parse, split and handle lines
 * @scanner : pointer to scanned data
 * Return: pointer to the parsed line
 */
char *line_parser(fd_t *scanner)
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
		for (i = 0; i < scan->data; ++i)
			if (scan->buffer[i] == '\n')
			{
				scan->buffer[++i] = '\0';
				 scan->data -= i;
				memcpy(line + data, scan->buffer, i);
				for (j = 0; i < READ_SIZE; ++j, ++i)
					scan->buffer[j] = scan->buffer[i];
				for (; j < READ_SIZE; ++j)
					scan->buffer[j] = '\0';
				return (line);
			}
		memcpy(line + data, scan->buffer, scan->data);
		data += scan->data;
		scan->data = read(scan->fd, scan->buffer, READ_SIZE);
	}
	return (line);
}
