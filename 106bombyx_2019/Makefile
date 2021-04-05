##
## EPITECH PROJECT, 2020
## Makefile for 104architect
## File description:
## Makefile
##

SRC	=	main.c	\
		description.c

LDFLAGS	=	-lm

CPPFLAGS	=	-Iinclude

CFLAGS	+=	-g3

OBJ	=	$(SRC:.c=.o)

NAME	=	106bombyx

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(LDFLAGS) $(CFLAGS) -o $(NAME) $(OBJ) $(CPPFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re
