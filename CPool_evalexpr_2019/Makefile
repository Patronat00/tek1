##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC	=	eval_expr.c

OBJ	=	 $(SRC:.c=.o)

NAME	=	eval_expr

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ ; $(MAKE) -f Makefile all
	gcc -o $(NAME) $(SRC) signe.c -L ./lib/my/ -lmy
clean:
	rm -f $(OBJ)
	cd lib/my/ && make clean

fclean:	clean
	rm -f $(NAME)
	rm -f lib/libmy.a
	cd lib/my/ && make fclean

re:	fclean all

auteur:
	echo $(USER) > auteur
