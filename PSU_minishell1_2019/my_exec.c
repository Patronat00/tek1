/*
** EPITECH PROJECT, 2020
** my_exec.c
** File description:
**  minishell boostrap
*/

#include <stdlib.h>
#include <unistd.h>
#include "util.h"
#include <stdio.h>
#include <fcntl.h>
#include "environment.h"

static void exit_shell(t_shell *shell, int status, char *message)
{
    if (message)
        my_putstr(message);
    shell->status = status;
}

static int open_file(const char *file_name, t_shell *shell)
{
    int file;

    if ((file = open(file_name, O_RDONLY)) == -1)
    {
        perror(file_name);
        shell->status = EXIT_FAILURE;
    }
    return (file);
}

int main (int ac, char **args, char **env)
{
    t_shell *shell;
    int status;
    int file;

    if(!(shell = malloc(sizeof(t_shell))))
        return EXIT_FAILURE;
    shell->env = copy_env(env, NULL);
    if((file = ac > 1 ? open_file(args[1], shell) : 0) != -1)
    {
        shell->tty = isatty(file);
        shell->exit = &exit_shell;
        start(shell, file);
        if (ac < 1 && shell->status != EXIT_FAILURE)
            close (file);
    }
    status = shell->status;
    free_tab(shell->env);
    free(shell);
    return status;
}