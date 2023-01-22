CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g

SRC0 = hnm.c utilities.c endian_switcher.c endian_switcher_2.c elf_type.c section_printer.c section_printer_2.c symbole_printer.c symbole_printer_2.c symbole_printer_3.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = hnm

.PHONY: all clean oclean flcean re

all: $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) $(OBJ0)

fclean: clean oclean

re: oclean all

hnm: hreadelf.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)
