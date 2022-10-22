#include "hls.h"

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument values
 * Return: int
 */
int main(int argc, char **argv)
{
	int i = 1, exit_status, called = 1;
	struct stat path;
	option_t opt = {0, 0, 0, 0, 0};

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	options_handler(argc, argv, &opt);
	file_handler(argc, argv, opt);
	while (i < argc)
	{
		if (argv[i][0] != '-' && !IS_REG(argv[i], path))
		{
			exit_status = _ls(argv[i], argv[0], &opt, &called);
			if (exit_status == 0)
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
int _ls(const char *dir, const char *prog_name, option_t *opt, int *called)
{
	struct dirent *d;
	DIR *dh;
	struct stat path;
	char buff[1024];
	if (IS_REG(dir, path))
		(*called)++;
	if (!dir || IS_REG(dir, path))
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
	if (( opt->files_nb < *called && opt->multi && opt->files_nb != 0))
	{
		printf("%s:\n", dir);
	}
	else if (opt->multi)
	{
		if (*called != 1 || opt->files_nb != 0)
			printf("\n");
		printf("%s:\n", dir);
	}
	(*called)++;
	d = readdir(dh);
	while (d != NULL)
	{
		if (d->d_name[0] != '.' || opt->hidden)
		{
			printf("%s", d->d_name);
			if (!opt->vertically)
			printf(" ");
			if (opt->vertically && (d = readdir(dh)) != NULL)
				printf("\n");
			else 
				d = readdir(dh);
		}
		else
			d = readdir(dh);
	}
	closedir(dh);
	return (EXIT_SUCCESS);
}
/**
 * file_handler - handling files
 * @argc: argcounter
 * @argv: argv
 * @opt: options
 * Return: int
 */
int file_handler(int argc, char **argv, option_t opt)
{
	int j = 1;
	struct stat path;

	while (opt.files_printed == 0 && j < argc)
	{
		while (j < argc)
		{
			if (argv[j][0] != '-')
			{
				if (IS_REG(argv[j], path))
				{
					is_last_reg(argc, argv, path);
					printf("%s", argv[j]);
					if (strcmp(argv[j], LAST_REG))
						printf("\n");
					opt.files_printed = 1;
				}
			}
			j++;
		}
	}
	return (EXIT_SUCCESS);
}
/**
 * is_last_reg - check if a file is last regular file
 * @argc: argcounter
 * @argv: argv
 * @p: struct stat
 * Return: int
 */
int is_last_reg(int argc, char **argv, struct stat p)
{
	int i = 1;

	while (i < argc)
	{
		if (IS_REG(argv[i], p))
		{
			#undef LAST_REG
			#define LAST_REG argv[i]
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
int IS_REG(const char * f, struct stat p)
{
	return (lstat(f, &p) == 0 && S_ISREG(p.st_mode));
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
	int i = 1, j = 1;
	struct stat path;

	while (j < argc)
	{
		if (argv[j][0] != '-')
		{
			if (IS_REG(argv[j], path))
				opt->files_nb++;
			if (IS_REG(argv[j], path) == 0)
				opt->dir_nb++;
		}
		j++;
	}
	if (opt->files_nb > 1 || opt->dir_nb > 1)
		opt->multi = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
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
		switch (*opts)
		{
		case '1':
			opt_struct->vertically = 1;
			break;
		case 'a':
			opt_struct->hidden = 1;
			break;
		default:
			break;
		}
		opts++;
	}
	return (EXIT_SUCCESS);
}
