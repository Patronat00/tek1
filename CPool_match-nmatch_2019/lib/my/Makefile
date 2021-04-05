##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task1Day10
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcncmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_isnum.c	\
		my_str_isupper.c	\
		my_str_islower.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncar.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_putchar.c	\

NAME    =       libmy.a

OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include
	gcc -o match *.c -I./include -L/lib/my/libmy.a
clean:
	rm -f $(OBJ) $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
