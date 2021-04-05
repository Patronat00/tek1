##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	my_strlen.c	\
		manual.c	\
		homer.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -lm

RM	=	rm -f

NAME	=	103cipher

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
