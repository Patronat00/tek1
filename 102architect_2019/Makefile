##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	archi.c	\
		my_str_isnum.c	\
		102architect.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -lm

RM	=	rm -f

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
