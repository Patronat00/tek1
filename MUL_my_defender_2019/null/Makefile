##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	menu.c	\
		sprite_positions.c	\
		play_and_help.c	\
		defender.c	\

OBJ	=	$(SRC:.c=.o)

CC	=	 gcc -l csfml-graphics -l csfml-audio -l csfml-window -l csfml-system -g3

RM	=	rm -f

NAME	=	my_defender

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
