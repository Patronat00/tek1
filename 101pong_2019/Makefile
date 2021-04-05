##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	pong_bootstrap.c	\
		lib/my/my_putchar.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -lm

RM	=	rm -f

NAME	=	101pong

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
