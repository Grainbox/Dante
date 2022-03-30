##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## make library
##

SRC	=	src/my_calloc.c 				\
		src/my_compute_power_rec.c		\
		src/my_compute_square_root.c	\
		src/my_find_prime_sup.c		\
		src/my_getnbr.c			\
		src/my_isneg.c			\
		src/my_is_prime.c			\
		src/my_putchar.c			\
		src/my_put_nbr.c			\
		src/my_putstr.c			\
		src/my_revstr.c			\
		src/my_showmem.c			\
		src/my_showstr.c			\
		src/my_sort_int_array.c		\
		src/my_strcapitalize.c		\
		src/my_strcat.c			\
		src/my_strcmp.c			\
		src/my_strcpy.c			\
		src/my_strdup.c 			\
		src/my_str_isalpha.c		\
		src/my_str_islower.c		\
		src/my_str_isnum.c			\
		src/my_str_isprintable.c		\
		src/my_str_isupper.c		\
		src/my_strlen.c			\
		src/my_strlowcase.c			\
		src/my_strncat.c			\
		src/my_strncmp.c			\
		src/my_strncpy.c			\
		src/my_strstr.c			\
		src/my_str_to_word_array.c		\
		src/my_strupcase.c			\
		src/my_swap.c	\
		src/my_printf_identifiers.c	\
		src/my_printf.c	\
		src/my_put_long_nbr.c	\
		src/my_printf_base_process.c	\
		src/my_printf_flags.c	\
		src/my_put_error.c	\
		src/my_number_to_string.c	\
		src/my_str_to_word_array2.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+= -I include -g

NAME	=	libmy.a

all: $(NAME)

debug: all
	gcc -o print $(SRC) main.c -I include -L -lmy

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f print

fclean: clean
	rm -f $(NAME)

re: fclean all
