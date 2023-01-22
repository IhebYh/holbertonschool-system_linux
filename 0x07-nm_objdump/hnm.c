#include "hreadelf.h"

int main(int argc, char **argv)
{
	elf_t elf_header;
	int fd, exit_status = 0;
	size_t r;

	memset(&elf_header, 0, sizeof(elf_header));
	if (argc != 2)
		return (fprintf(stderr, USAGE_ERR), EXIT_FAILURE);
	
	fd = open_file(argv[1], 0);
	if (fd == -1)
		return (EXIT_FAILURE);

	r = read(fd, &elf_header.e64, sizeof(elf_header.e64));
	if (r != sizeof(elf_header.e64) || elf_checker((char *) &elf_header.e64))
	{
		fprintf(stderr, "%s: %s: File format 
		not recognized\n", MYNAME, argv[1]);
		exit_status = EXIT_FAILURE;
	}
	else
	{
		size_t printed_num = 0;

		if(is_32(elf_header.e64))
		{
			lseek(fd, 0, SEEK_SET);
			r = read(fd, &elf_header.e32, sizeof(elf_header.e32));
			if (r != sizeof(elf_header.e32) || elf_checker((char *)&elf_header.e32))
			{
				fprintf(stderr, NOT_MAGIC_ERR);
				exit_status = EXIT_FAILURE;
			}
		}
		switch_all_endian(&elf_header);
		exit_status = print_all_symbol_tables(&elf_header, fd, &printed_num);
		if (!num_printed)
			fprintf(stderr, "%s: %s: no symbols\n", MYNAME, argv[1]);
	}
	free(elf_header.s32);
	free(elf_header.s64);
	free(elf_header.p32);
	free(elf_header.p64);
	close(fd);
	return (exit_status);
}
