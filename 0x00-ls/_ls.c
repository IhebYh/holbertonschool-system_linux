#include "hls.h"

/**
 * main - entry point
 *
 * Return: int
 */
int main(int argc, char **argv)
{
	int i = 1, exit_status;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		exit_status =_ls(argv[i], argv[0], argc > 2);
		i++;
	}
	return (exit_status);
}

/**
 * _ls - main function containing the functions
 * needed to get the GNU/Linux command ls
 * @dir : directory name
 * Return: void
 */
int _ls(const char *dir, const char *prog_name, int multi)
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
	if (multi)
		printf("%s:\n", dir);
	while ((d = readdir(dh)) != NULL)
	{
		if (d->d_name[0] != '.')
			printf("%s ", d->d_name);
	}
	printf("\n");
	closedir(dh);
	return (EXIT_SUCCESS);
}
