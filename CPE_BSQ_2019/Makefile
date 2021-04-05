##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_getnbr.c	\
		bsq.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	bsq


all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
