##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	105torus.c   \
		help.c  \
		which_algo.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-lm

RM	=	rm -f

NAME	=	105torus

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
