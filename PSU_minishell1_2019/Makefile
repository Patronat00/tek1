##
## EPITECH PROJECT, 2019
## Makefile for finalstumper
## File description:
## 26/10/19
##

SRC	=       my_exec.c   \
            cd.c    \
            env.c   \
            env_alt.c   \
            exec.c  \
            exit.c  \
            minishell.c \
            scan.c  \
            setenv.c    \
            shell.c \
            str.c   \
            str2.c  \
            tab.c   \
            unsetenv.c  \
            lib/my/my_putstr.c  \
            lib/my/my_putchar.c \
            lib/my/my_strlen.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

NAME	=	mysh


all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
