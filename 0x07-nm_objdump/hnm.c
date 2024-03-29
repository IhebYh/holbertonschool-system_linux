#include "hreadelf.h"

/**
 * main - entry point
 * @ac: argument count
 * @argv: argument vector
 * Return: 0 on success or 1+ on error
 */
int main(int ac, char **argv)
{
	int ret = EXIT_SUCCESS;
	char **_argv = argv;

	if (ac < 2)
		return (fprintf(stderr, USAGE_ERR), EXIT_FAILURE);
	if (ac == 2)
		return (file_processor(argv[1], 0, argv));
	while (*++_argv)
		ret += file_processor(*_argv, 1, argv);
	return (ret);
}

/**
 * file_processor - displays symbols for 1 file
 * @file_name: name of file to process
 * @multiple: 1 if there are multiple files else 0
 * @argv: the argument vector
 * Return: 0 on success else 1 on error
 */
int file_processor(char *file_name, int multiple, char **argv)
{
	int fd, exit_status = 0;
	size_t r, num_printed = 0;
	elf_t elf_header;

	memset(&elf_header, 0, sizeof(elf_header));

	fd = open_file(file_name, 0, argv);
	if (fd == -1)
		return (EXIT_FAILURE);

	r = read(fd, &elf_header.e64, sizeof(elf_header.e64));
	if (r != sizeof(elf_header.e64) || elf_checker((char *)&elf_header.e64))
	{
		fprintf(stderr, "%s: %s: File format not recognized\n", argv[0], file_name);
		exit_status = EXIT_FAILURE;
	}
	else
	{
		if (is_32(elf_header.e64))
		{
			lseek(fd, 0, SEEK_SET);
			r = read(fd, &elf_header.e32, sizeof(elf_header.e32));
			if (r != sizeof(elf_header.e32) || elf_checker((char *)&elf_header.e32))
				exit_status = (fprintf(stderr, NOT_MAGIC_ERR, argv[0]), EXIT_FAILURE);
		}
		if (multiple)
			printf("\n%s:\n", file_name);
		switch_all_endian(&elf_header);
		exit_status = print_all_symbol_tables(&elf_header, fd, &num_printed);
		if (!num_printed)
			fprintf(stderr, "%s: %s: no symbols\n", argv[0], file_name);
	}
	free(elf_header.s32);
	free(elf_header.s64);
	free(elf_header.p32);
	free(elf_header.p64);
	close(fd);
	return (exit_status);
}
