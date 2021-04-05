##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## making file
##

SRC	=	src/eval_expr_calcul.c		\
		src/findop.c	\
		src/signe.c	\
		src/my_getnbr.c		\
		src/my_putchar.c	\
		src/my_put_nbr.c	\
		src/infin_add.c		\
		src/my_putstr.c		\
		src/my_strlen.c		\
		src/bistromatic.h	\
		src/my_atoi.c	\
		src/main.c	\
		src/eval_expr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	calc

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g3 -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f src/*.o

re:	fclean all
