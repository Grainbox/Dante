##
## EPITECH PROJECT, 2021
## navy
## File description:
## Makefile
##

SRC	=	main_solver.c	\
		displays.c	\
		parse_buffer.c	\
		solver.c		\
		intersection.c	\
		read_way.c		\
		get_direction.c	\
		inter_process.c

OBJ = $(SRC:.c=.o)

NAME = solver

CFLAGS	+= -Wall -Wextra -W -I ../include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ../lib/my/
	gcc -o $(NAME) $(OBJ) -L ../lib/my -lmy

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f vgcore*

fclean: clean
	make fclean -C ../lib/my/
	rm -f $(NAME)

re: fclean	all

.PHONY: clean fclean re
