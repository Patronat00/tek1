##
## EPITECH PROJECT, 2020
## Makefile for dante generator
## File description:
## Makefile
##

SRC	=	my_putstrv_2.c	\
		solve.c	\
		mal_n.c	\
		maze.c	\
		my_strlen.c	\

CPPFLAGS	=	-Iinclude
OBJ	=	$(SRC:.c=.o)

NAME	=	solver

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re
