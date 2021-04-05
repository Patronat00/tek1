##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	lib/my/my_putchar.c	\
		lib/my/my_putstr.c	\
		lib/my/my_put_nbr.c	\
		lib/my/my_strlen.c	\
		lib/my/my_getnbr.c	\
		lib/my/my_realloc.c	\
		lib/my/my_showmem.c	\
		lib/my/my_memset.c	\
		lib/my/my_swap.c	\
		lib/my/my_strcat.c	\
		src/display.c	\
		src/main.c	\
		src/go_map.c	\
		src/match_fonct.c	\
		src/game.c	\
		src/handle_ai.c	\
		src/map_free.c	\
		src/player_play.c	\

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	matchstick

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
