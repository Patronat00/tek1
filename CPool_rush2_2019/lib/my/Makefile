##
## EPITECH PROJECT, 2019
## Makefile d10
## File description:
##
##

SRC	=	my_putchar.c \
		my_put_nbr.c \
		my_strlen.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../$(NAME)

	cd delivery/CPool_rush2 ; $(MAKE) -f Makefile

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
