/*
** EPITECH PROJECT, 2020
**  enc.c
** File description:
**  minishell
*/

#include "environment.h"
#include "util.h"
#include <unistd.h>
#include <stdlib.h>

static int	count_similar_keys(char **a, char **b)
{
    char *str;
    char *need_free;
    char **split;
    int	i;

    i = 0;
    while (a && (str = *a++))
    {
        split = splitstr((need_free = strdupl(str)), '=');
        if (tab_start_withstr(b, split[0]))
            i++;
        free(need_free);
        free(split);
    }
    return (i);
}

char **copy_env(char **env, char **overwrite)
{
    char *str;
    char *need_free;
    char **split;
    char *var;
    int added;
    char **new;
    char **hold;

    added = tab_length(env) - count_similar_keys(env, overwrite);
    if (!(hold = (new  = malloc(sizeof(char *) * (tab_length(env) + added + 1)))))
        return (NULL);
    while(env && (str = *env++))
    {
        split = splitstr((need_free = strdupl(str)), '=');
        *new++ = strdupl(((var = tab_start_withstr(overwrite, split[0])) &&
                          overwrite++ ? var : str));
        free(need_free);
        free(split);
    }
    while (overwrite && *overwrite)
        *new++ = *overwrite++;
    *new = 0;
    return (hold);
}

char  **get_paths(char **env)
{
    char  *str;

    while ((str = *env++))
        if (start_withstr(str, "PATH"))
            return (splitstr(strdupl(str + 5), ':'));
    return (NULL);
}
