/*
** EPITECH PROJECT, 2020
** shell.c
** File description:
**  minishell
*/

#include "minishell.h"
#include "util.h"
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "builtin.h"

static bool values;

static void fast_display()
{
    char *sub;
    char path[1024];

    sub = NULL;
    if(getcwd(path, 1024))
    {
        my_putstr(count_char(path, '/') > 2 ?
                (sub = rev_substr(path, '/', 2)) : path);
        my_putchar('>');
        if (sub)
            free(sub);
    }
    else
        perror("getcwd");
}

static void exit_case ()
{
    my_putchar('\n');
    if (!values)
        fast_display();
}

static void apply_command (t_shell *shell, char *cmd_line) {
    char **args;
    char *need_free;
    static void (*const cmds[6])(struct s_shell *shell, char **args) =
            {
                    &cd_alt, &setenv_alt, &unsetenv_alt, &env_alt, &exit_alt, &search_cmd
            };

    args = splitstr(strdupl(cmd_line), ' ');
    if (args && *args)
        cmds[get_cmd_index(*args)](shell, args);
    free(*args);
    free(args);
}

void start (t_shell *shell, int file)
{
    char *cmds_line;
    char **cmds;
    int i;

    signal(SIGINT, &exit_case);
    while (shell->status == - 1)
    {
        values = false;
        if (shell->tty)
            fast_display();
        if (!(cmds_line = scan_line(file)))
            shell->exit(shell, EXIT_SUCCESS, shell->tty ? "exit\n" : NULL);
        else
        {
            values = true;
            cmds = splitstr(cmds_line, ';');
            i = -1;
            while (cmds[++i])
                apply_command(shell, cmds[i]);
            free(cmds);
            free(cmds_line);
        }
    }
}

int get_cmd_index(char *str)
{
    return (equalstr(str, "cd") ? CD :
        equalstr(str, "setenv") ? SETENV :
        equalstr(str, "unsetenv") ? UNSETENV :
        equalstr(str, "env") ? ENV :
        equalstr(str, "exit") ? EXIT : SEARCH_CMD);
}