##
## EPITECH PROJECT, 2020
## Makefile for dante generator
## File description:
## Makefile
##

SRC	=	main.c	\
		check_error.c	\
		display.c	\
		initiate_maze.c	\
		my_strcmp.c	\
		not_perfect_maze.c	\
		not_perfect_generator.c	\
		perfect_maze.c	\
		allocate_map.c	\
		create_map.c	\
		perfect_generator.c	\
		swap_forward_and_right.c	\
		two_sides.c	\
		algo.c

CPPFLAGS	=	-Iinclude

OBJ	=	$(SRC:.c=.o)

NAME	=	generator

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: clean fclean re
