##
## EPITECH PROJECT, 2021
## navy
## File description:
## Makefile
##

SRC	=	generator.c				\
		error_handling.c		\
		generate_perfect.c		\
		create_tabs.c			\
		open_walls.c			\
		generate_imperfect.c

OBJ = $(SRC:.c=.o)

NAME = generator

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
