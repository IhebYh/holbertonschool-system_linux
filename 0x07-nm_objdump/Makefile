CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

SRC0 = hnm.c utilities.c endian_switcher.c endian_switcher_2.c elf_type.c section_printer.c section_printer_2.c symbole_printer.c symbole_printer_2.c symbole_printer_3.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = hnm

SRC1 = hobjdump.c hobjdump_2.c hobjdump_3.c utilities.c endian_switcher.c endian_switcher_2.c elf_type.c section_printer.c section_printer_2.c symbole_printer_2.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = hobjdump

.PHONY: all clean oclean flcean re

all: $(OBJ0) $(OBJ1)
		$(CC) $(OBJ0) -o $(NAME0)
		$(CC) $(OBJ1) -o $(NAME1)
clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)

fclean: clean oclean

re: oclean all

hnm: hreadelf.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

hobjdump: hreadelf.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)
