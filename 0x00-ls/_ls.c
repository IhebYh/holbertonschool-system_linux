#include "hls.h"


int main()
{
	return (_ls("."));
}

/**
 * _ls - main function containing the functions
 * needed to get the GNU/Linux command ls
 * @dir : directory name
 * Return: void
 */
int _ls(const char *dir)
{
	struct dirent *d;
	DIR *dh;

	if (!dir)
		return (1);
	
	dh = opendir(dir);
	while ((d = readdir(dh)) != NULL)
	{
		printf("%s ", d->d_name);
	}
	printf("\n");
	closedir(dh);
	return (0);
}
