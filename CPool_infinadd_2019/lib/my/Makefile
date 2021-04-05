##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

SRC     = 	my_putchar.c \
		my_put_nbr.c \
		my_strlen.c \
		my_getnbr.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../../$(NAME)

clean:
	rm -f $(OBJ) $(NAME)

fclean: clean
	rm -f $(NAME)

re:	fclean all
