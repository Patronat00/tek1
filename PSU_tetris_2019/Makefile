##
## EPITECH PROJECT, 2020
## Makefile for 104architect
## File description:
## Makefile
##

SRC	=	check_tetrimino.c	\
		help.c	\

CPPFLAGS	=	-Iinclude

CFLAGS	+=	-g3

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)
	find . -name "*~" -delete -o -name "#*#" -delete

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re
