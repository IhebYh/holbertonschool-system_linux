#ifndef _HREADELF_H_
#define _HREADELF_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <elf.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#define EGET(x) \
	(is_32(elf_header->e64) ? elf_header->e32.x : elf_header->e64.x)
#define SGET(i, x) \
	(is_32(elf_header->e64) ? elf_header->s32[i].x : elf_header->s64[i].x)
#define PGET(i, x) \
	(is_32(elf_header->e64) ? elf_header->p32[i].x : elf_header->p64[i].x)
#define YGET(i, x) \
	(is_32(elf_header->e64) ? elf_header->y32[i].x : elf_header->y64[i].x)
#define USAGE_ERR "0-hreadelf elf_filename\n"
#define MYNAME "0-hreadelf"
#define ERR_PREFIX MYNAME ": Error: "
#define ERR_NO_ENTRY ERR_PREFIX \
	"'%s': No such file\n"
#define ERR_NO_ACCESS ERR_PREFIX \
	"Input file '%s' is not readable.\n"
#define NOT_MAGIC_ERR ERR_PREFIX \
	"Not an ELF file - it has the wrong magic bytes at the start\n"
#define is_32(x) ((x).e_ident[EI_CLASS] == ELFCLASS32)
#define is_64 ((elf_header->e64).e_ident[EI_CLASS] == ELFCLASS64)
#define is_be(x) ((x).e_ident[EI_DATA] == ELFDATA2MSB)

/**
 * struct Elf - stores 32/64 structs and other data
 * @e64: the 64 bit struct
 * @e32: the 32 bit struct
 * @s64: the 64 bit struct section array
 * @s32: the 32 bit struct section array
 * @p64: the 64 bit struct program array
 * @p32: the 32 bit struct program array
 * @sy64: the 64 bit struct symbol array
 * @sy32: the 32 bit struct symbol array
 */
typedef struct Elf
{
	Elf64_Ehdr e64;
	Elf32_Ehdr e32;
	Elf64_Shdr *s64;
	Elf32_Shdr *s32;
	Elf64_Phdr *p64;
	Elf32_Phdr *p32;
	Elf64_Sym *y64;
	Elf32_Sym *y32;

} elf_t;
/******* FUNCTION'S CALL *******/

/**** utilities.c *******/
int open_file(char *name, int silent);
int elf_checker(char *elf_header);
void print_bytes(void *ptr, size_t n);

/**** endian_switcher.c *******/
unsigned short switch_endian2(unsigned short n);
unsigned int switch_endian4(unsigned int n);
unsigned long switch_endian8(unsigned long n);
void switch_all_endian(elf_t *h);
void switch_all_endian_section(elf_t *h, size_t i);

/* endian_switcher_2.c */
void switch_all_endian_program(elf_t *h, size_t i);
void switch_all_endian_symbol(elf_t *h, size_t i);
void switch_all_endian_ver(elf_t *h, uint16_t *versym, size_t versym_size,
	Elf64_Verneed *verneed, size_t verneed_size);

/* header_printer.c */
int print_header(elf_t *elf_header);
int print_magic(Elf64_Ehdr *elf_header);
int print_class(Elf64_Ehdr *elf_header);
int print_data(Elf64_Ehdr *elf_header);
int print_version(Elf64_Ehdr *elf_header);

/* header_printer_2.c */
int print_osabi(Elf64_Ehdr *elf_header);
int print_osabi_more(Elf64_Ehdr *elf_header);
int print_abiversion(Elf64_Ehdr *elf_header);
int print_type(elf_t *elf_header);
int print_entry(elf_t *elf_header);

/* header_printer_3.c */
int print_machine(Elf64_Ehdr *elf_header);
int print_e_version(elf_t *elf_header);
int print_program_headers(elf_t *elf_header);
char *get_machine(Elf64_Ehdr *elf_header);
char *get_machine2(Elf64_Ehdr *elf_header);

/* header_printer_4.c */
int print_section_headers(elf_t *elf_header);
int print_flags(elf_t *elf_header);

/* section_printer.c */
int print_section_headers_full(elf_t *elf_header, int fd);
void read_section_headers(elf_t *elf_header, int fd);
char *read_string_table(elf_t *elf_header, int fd);
char *get_section_type(unsigned int sh_type);

/* section_printer_2.c */
void print_section_headers32(elf_t *elf_header, char *string_table);
void print_section_headers64(elf_t *elf_header, char *string_table);
char *get_section_flags(elf_t *elf_header, size_t i);

/* elf_type.c */
char *get_type(elf_t *elf_header);

/* program_printer.c */
int print_program_headers_full(elf_t *elf_header, int fd);
void print_program_headers32(elf_t *elf_header, char *string_table, int fd);
void print_program_headers64(elf_t *elf_header, char *string_table, int fd);
void read_program_headers(elf_t *elf_header, int fd);
char *get_segment_type(unsigned long p_type);

/* program_printer.c */
int print_section_to_segment_mapping(elf_t *elf_header, char *string_table);

/* symbole_printer.c */
int print_all_symbol_tables(elf_t *elf_header, int fd);
void print_symbol_table(elf_t *elf_header, int fd, size_t i,
	char *string_table);
void print_symbol_table32(elf_t *elf_header, char *string_table,
	char *sym_string_table, uint16_t *versym, Elf64_Verneed *verneed,
	size_t verneed_size, int section);
void print_symbol_table64(elf_t *elf_header, char *string_table,
	char *sym_string_table, uint16_t *versym, Elf64_Verneed *verneed,
	size_t verneed_size, int section);
void print_verneed_info(elf_t *elf_header, char *sym_string_table,
	uint16_t *versym, Elf64_Verneed *verneed, size_t verneed_size, size_t i,
	size_t size, int section);

/* symbole_printer_2.c */
void read_symbol_table(elf_t *elf_header, int fd, int i);
char *read_symbol_string_table(elf_t *elf_header, int fd, int i);
size_t find_verneed_index(Elf64_Verneed *verneed, size_t verneed_size,
	size_t index);
void print_verneed_table(elf_t *elf_header, int fd, int i,
	char *sym_string_table, uint16_t *versym, Elf64_Verneed *verneed);
void *read_data(elf_t *elf_header, int fd, unsigned long offset, long size);

/* symbole_printer_3.c */
char *get_sym_type(elf_t *elf_header, size_t i);
char *get_sym_bind(elf_t *elf_header, size_t i);
char *get_sym_visibility(elf_t *elf_header, size_t i);

#endif /* _HREADELF_H_ */
