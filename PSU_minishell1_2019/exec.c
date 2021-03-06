/*
** EPITECH PROJECT, 2020
**  exec.c
** File description:
**  minishell
*/

#include "environment.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "minishell.h"
#include "util.h"
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>

static void execute(t_shell *shell, char *path, char **args)
{
    pid_t dip;
    int	wstatus;

    if ((dip = fork()) == -1)
        perror("fork");
    else if (dip == CHILD_PROCESS && execve(path, args, shell->env) == -1)
    {
        perror("execve");
        shell->exit(shell, EXIT_FAILURE, NULL);
    }
    else
        while (waitpid(dip, &wstatus, 0) != -1 &&
               !WIFEXITED(wstatus))
            if (WIFSIGNALED(wstatus) && WTERMSIG(wstatus) == SIGSEGV)
                my_putstr(SEGFAULT_STR);
}

static int try_exec_access(char *path, char **denied, bool freepath)
{
    struct stat rights;
    int	right;

    if (access(path, F_OK) != -1 && access(path, X_OK) != -1)
        if (!stat(path, &rights) && rights.st_mode & S_IXUSR)
            right = ACCESS;
        else
        {
            safe_free(*denied);
            *denied = path;
            right = DENIED;
        }
    else
        right = NOT_FOUND;
    if (right == NOT_FOUND && freepath)
        safe_free(path);
    return (right);
}

static int check_paths(t_shell *shell, char **args, char **denied)
{
    char *str;
    char **hold;
    char **paths;
    int right;

    paths = (hold = get_paths(shell->env));
    right = NOT_FOUND;
    while (paths && (str = *paths++))
    {
        str = concatstr(str, "/", false);
        str = concatstr(str, *args, true);
        if ((right = try_exec_access(str, denied, true)) == ACCESS)
        {
            execute(shell, str, args);
            free(str);
            break;
        }
    }
    safe_freesub(hold, true);
    return (right);
}

void search_cmd(t_shell *shell, char **args)
{
    char *str;
    char *denied;
    int	right;
    bool has_slash;

    denied = NULL;
    if ((has_slash = count_char(*args, '/') > 0) &&
        (right = try_exec_access(*args, &denied, false)) == ACCESS)
        execute(shell, *args, args);
    else if (!has_slash)
        right = check_paths(shell, args, &denied);
    my_putstr(right == ACCESS ? NULL : denied ? denied : args[0]);
    my_putstr(right == ACCESS ? NULL : denied ? DENIED_STR : NFOUND_STR);
    safe_free(denied);
}
