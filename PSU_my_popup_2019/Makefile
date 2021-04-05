##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	my_strlen.c	\
		my_popup.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -lncurses

RM	=	rm -f

NAME	=	my_popup

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
