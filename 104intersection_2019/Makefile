##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=	src/help.c	\
		src/which_calc.c    \
		src/104intersection.c   \
		src/delta_negative.c    \
		src/delta_null.c  \
		src/delta_positive.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	=	-lm -I./include

RM	=	rm -f

NAME	=	104intersection

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
