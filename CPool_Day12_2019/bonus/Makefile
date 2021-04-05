##
## EPITECH PROJECT, 2019
## Makefile rush2
## File description:
##
##

SRC	=	cat.c

NAME	=	cat

LIB     =       libmy.a


all:	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC) $(LIB) 

clean:
	rm -f $(NAME) $(LIB)

fclean: clean
	rm -f $(NAME)

re:	fclean all
