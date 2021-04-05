##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	lib/my/my_strlen.c	\
		lib/my/my_putchar.c \
		lib/my/my_putstr.c  \
		lib/my/my_getnbr.c  \
		manual.c	\
		lenght_line.c  \
		movements_down.c \
		movements_right.c \
		movements_left.c    \
		movements_up.c  \
		my_sokoban.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc -lncurses

RM	=	rm -f

NAME	=	my_sokoban

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
