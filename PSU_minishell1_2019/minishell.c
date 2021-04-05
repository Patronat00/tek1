/*
** EPITECH PROJECT, 2020
** shell.c
** File description:
**  minishell
*/

#include "util.h"
#include <stdlib.h>

bool safe_free(void *ptr)
{
    bool done;

    if ((done = ptr != NULL))
        free(ptr);
    return (done);
}

bool safe_freesub(char **ptr, bool free_sub)
{
    bool done;

    if ((done = ptr != NULL))
    {
        if (free_sub && (done = *ptr != NULL))
            free(*ptr);
        free(ptr);
    }
    return (done);
}