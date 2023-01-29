C= gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu99 -g

SRC0 = strace_0.c
OBJ0 = $(SRC0:.c=.o)
NAME0 = strace_0

SRC1 = strace_1.c
OBJ1 = $(SRC1:.c=.o)
NAME1 = strace_1

SRC2 = strace_2.c
OBJ2 = $(SRC2:.c=.o)
NAME2 = strace_2

SRC3 = strace_3.c
OBJ3 = $(SRC3:.c=.o)
NAME3 = strace_3

SRC4 = strace_4.c
OBJ4 = $(SRC4:.c=.o)
NAME4 = strace_4

SRC5 = strace_5.c
OBJ5 = $(SRC5:.c=.o)
NAME5 = strace_5

SRC6 = strace_6.c strace_6_2.c
OBJ6 = $(SRC6:.c=.o)
NAME6 = strace_6

SRC7 = strace_7.c strace_7_2.c
OBJ7 = $(SRC7:.c=.o)
NAME7 = strace_7

SRC8 = strace_8.c strace_8_2.c strace_8_3.c
OBJ8 = $(SRC8:.c=.o)
NAME8 = strace_8

.PHONY: all clean oclean flcean re

all: $(OBJ0) $(OBJ1)
	$(CC) $(OBJ0) -o $(NAME0)
	$(CC) $(OBJ1) -o $(NAME1)
	$(CC) $(OBJ2) -o $(NAME2)
	$(CC) $(OBJ3) -o $(NAME3)
	$(CC) $(OBJ4) -o $(NAME4)
	$(CC) $(OBJ5) -o $(NAME5)
	$(CC) $(OBJ6) -o $(NAME6)
	$(CC) $(OBJ7) -o $(NAME7)
	$(CC) $(OBJ8) -o $(NAME8)

clean:
	$(RM) *~ $(NAME0)
	$(RM) *~ $(NAME1)
	$(RM) *~ $(NAME2)
	$(RM) *~ $(NAME3)
	$(RM) *~ $(NAME4)
	$(RM) *~ $(NAME5)
	$(RM) *~ $(NAME6)
	$(RM) *~ $(NAME7)
	$(RM) *~ $(NAME8)

oclean:
	$(RM) $(OBJ0)
	$(RM) $(OBJ1)
	$(RM) $(OBJ2)
	$(RM) $(OBJ3)
	$(RM) $(OBJ4)
	$(RM) $(OBJ5)
	$(RM) $(OBJ6)
	$(RM) $(OBJ7)
	$(RM) $(OBJ8)

fclean: clean oclean

re: oclean all

strace_0: syscalls.h $(OBJ0)
	$(CC) $(OBJ0) -o $(NAME0)

strace_1: syscalls.h $(OBJ1)
	$(CC) $(OBJ1) -o $(NAME1)

strace_2: syscalls.h $(OBJ2)
	$(CC) $(OBJ2) -o $(NAME2)

strace_3: syscalls.h $(OBJ3)
	$(CC) $(OBJ3) -o $(NAME3)

strace_4: syscalls.h $(OBJ4)
	$(CC) $(OBJ4) -o $(NAME4)

strace_5: syscalls.h $(OBJ5)
	$(CC) $(OBJ5) -o $(NAME5)

strace_6: syscalls.h $(OBJ6)
	$(CC) $(OBJ6) -o $(NAME6)

strace_7: syscalls.h $(OBJ7)
	$(CC) $(OBJ7) -o $(NAME7)

strace_8: syscalls.h $(OBJ8)
	$(CC) $(OBJ8) -o $(NAME8)