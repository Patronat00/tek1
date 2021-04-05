##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make
##

SRC	=	infi_add.c

OBJ	=	$(SRC:.=.o=)

NAME	=	infin_add

CFLAGS =	-W -Wall -I include/ -L ./ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my/ ; $(MAKE) -f Makefile all
	rm -f *.o
	gcc -o $(NAME) $(SRC) $(CFLAGS)

clean:
	rm -f $(NAME)
	rm -f *.o
	rm -f *~
	rm -f libmy.a
	cd lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd lib/my && make fclean

re:	fclean all
