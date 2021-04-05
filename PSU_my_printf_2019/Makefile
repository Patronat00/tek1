##
## EPITECH PROJECT, 2019
## Makef	ile
## File description:
## task1Day10
##

SRC	=	my_printf.c	\
		lib/my/my_putchar.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c	\
		lib/my/my_revstr.c	\
		src/decimal_to_octal.c	\
		src/dec_to_hexa.c	\
		src/decimal_to_binary.c	\
		src/decimal_to_little_hexa.c

NAME    =       libmy.a

OBJ	=	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) $(NAME)

fclean:	clean
	rm -f $(NAME)
	rm -f a.out

re:	fclean all
