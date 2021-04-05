##
## EPITECH PROJECT, 2019
## Makefile_for_my_defender
## File description:
## Makefile
##

SRC =	$(shell find ./src -name *.c)


OBJ	=	$(SRC:.c=.o)

NAME 	=	my_defender

CFLAGS	= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -g3 -Wall -Wextra 

CPPFLAGS = -I include/ -g3
all: 	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(OBJ)
	mkdir -p ../../include

clean:
	@echo -e "\e[1m\e[32m******************************** NETTOYAGE de tous les objet ************************************\033[0m"
	rm -f $(OBJ)
	rm -f vgcore.*
	@echo -e "\e[1m\e[32m******************************** FIN du nettoyages ************************************\033[0m"

re: fclean all

fclean:	clean
	rm -f $(NAME)
.PHONY:	clean
