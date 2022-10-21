#include "hls.h"

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument values
 * Return: int
 */
int main(int argc, char **argv)
{
	int i = 1, exit_status;
	option_t opt = {0, 0, 0};

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	options_handler(argc, argv, &opt);
	if (argc > 3)
		opt.multi = 1;
	while (i < argc)
	{
		if (opt.pos != i)
		{
			exit_status = _ls(argv[i], argv[0], opt);
			printf("\n");
		}
		i++;
	}
	return (exit_status);
}

/**
 * _ls - main function containing the functions
 * needed to get the GNU/Linux command ls
 * @dir : directory name
 * @prog_name: program name
 * @opt: options
 * Return: void
 */
int _ls(const char *dir, const char *prog_name, option_t opt)
{
	struct dirent *d;
	DIR *dh;
	char buff[1024];

	if (!dir)
		return (EXIT_FAILURE);
	dh = opendir(dir);
	if (!dh)
	{
		buff[0] = 0;
		if (errno == ENOENT)
			sprintf(buff, "%s: cannot access %s", prog_name, dir);
		else if (errno == EACCES)
			sprintf(buff, "%s: cannot open directory %s", prog_name, dir);
		perror(buff);
		return (EXIT_FAILURE);
	}
	if (opt.multi)
		printf("%s:\n", dir);
	while ((d = readdir(dh)) != NULL)
	{
		if (d->d_name[0] != '.')
		{
			if (opt.vertically)
			{
			printf("%s", d->d_name);
			printf("\n");
			}
			else
			{
				printf("%s ", d->d_name);
			}
		}
	}
	closedir(dh);
	return (EXIT_SUCCESS);
}

/**
 * options_handler - handling options for ls command
 *
 * @argc: argument counter
 * @argv: arguments list
 * @opt: options structure
 * Return: int
 */
int options_handler(int argc, char **argv, option_t *opt)
{
	int i = 1;

	while (i < argc)
	{
		if (*argv[i] == '-')
		{
			opt->pos = i;
			options_builder(argv[i], opt);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	return (EXIT_FAILURE);
}

/**
 * options_builder - building options for ls command
 *
 * @opts: list of options
 * @opt_struct: options structure
 * Return: int
 */
int options_builder(char *opts, option_t *opt_struct)
{
	while (*opts != '\0')
	{
		opts++;
		switch (*opts)
		{
		case '1':
			opt_struct->vertically = 1;
			break;
		default:
			break;
		}
	}
	return (EXIT_SUCCESS);
}
