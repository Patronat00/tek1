/*
** EPITECH PROJECT, 2020
**  exit.c
** File description:
**  minishell
*/

#include "builtin.h"
#include <stdlib.h>

void	exit_alt(t_shell *shell, char **args)
{
    shell->exit(shell, EXIT_SUCCESS, shell->tty ? "exit\n" : NULL);
}