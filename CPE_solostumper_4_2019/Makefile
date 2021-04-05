##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	main.c \
		to_lower2.c	\
		lib/my/my_putchar.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	geekNameFormatter


all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
