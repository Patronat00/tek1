##
## EPITECH PROJECT, 2020
## Makefile for dante generator
## File description:
## Makefile
##

GENERATOR	=	generator/

SOLVER	=	solver/

all:
	make -C $(GENERATOR)
	make -C $(SOLVER)

clean:
	make -C $(GENERATOR) clean
	make -C $(SOLVER) clean

fclean: clean
	make -C $(GENERATOR) fclean
	make -C $(SOLVER) fclean

re: clean fclean all

.PHONY: clean fclean re
