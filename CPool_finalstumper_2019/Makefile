##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	finalstumper.c	\
		rush3.c	\
		src/my_putchar.c	\
		src/my_strlen.c	\
		src/my_put_nbr.c	\
		src/my_putstr.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

NAME	=	rush3

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
