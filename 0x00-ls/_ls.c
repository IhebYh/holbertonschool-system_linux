#include "hls.h"

/**
 * _ls - main function containing the functions
 * needed to get the GNU/Linux command ls
 * @dir : directory name
 * Return: void
 */
void _ls(const char *dir)
{
	struct dirent *d;
	DIR *dh = opendir(dir);

	while ((d = readdir(dh)) != NULL)
	{
		printf("%s  ", d->d_name);
	}
	printf("\n");
}
