##
## EPITECH PROJECT, 2021
## navy
## File description:
## Makefile
##

SRC1	=	solver/main_solver.c			\
			solver/displays.c		\
			solver/parse_buffer.c	\
			solver/solver.c			\
			solver/intersection.c	\
			solver/read_way.c		\
			solver/get_direction.c	\
			solver/inter_process.c	\

SRC2	=	generator/generator.c			\
			generator/error_handling.c		\
			generator/generate_perfect.c	\
			generator/create_tabs.c			\
			generator/open_walls.c			\
			generator/generate_imperfect.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

NAME1 = tmp_solver

NAME2 = tmp_generator

CFLAGS	+= -Wall -Wextra -W -I include -g

all:	$(NAME1)	$(NAME2)

$(NAME1):	$(OBJ1)
	make -C lib/my/
	gcc -o $(NAME1) $(OBJ1) -L lib/my -lmy
	mv $(NAME1) solver/solver

$(NAME2):	$(OBJ2)
	make -C lib/my/
	gcc -o $(NAME2) $(OBJ2) -L lib/my -lmy
	mv $(NAME2) generator/generator

clean:
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f *~
	rm -f vgcore*

fclean: clean
	make fclean -C lib/my/
	rm -f solver/solver
	rm -f generator/generator

re: fclean	all

.PHONY: clean fclean re
