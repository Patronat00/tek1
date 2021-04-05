/*
** EPITECH PROJECT, 2020
** str2.c
** File description:
**  minishell
*/

#include <stdbool.h>
#include "util.h"
#include <stdlib.h>

bool start_withstr(char *str, char *charset)
{
    if (!str || !charset)
        return (false);
    while (*charset)
        if (*str++ != *charset++)
            return (false);
    return (true);
}

char *strdupl(char *str)
{
    char *new;
    char *hold;

    if (!(hold = (new = malloc(sizeof(char) * (my_strlen(str) + 1)))))
        return (NULL);
    while (*str)
        *new++ = *str++;
    *new = 0;
    return (hold);
}

char *concatstr(char *a, char *b, bool free_a)
{
    char *concat;
    char *hold;
    char *hold_a;

    if (!(hold = (concat = malloc(sizeof(char) * (my_strlen(a) +
                                                  my_strlen(b) + 1)))))
        return (NULL);
    hold_a = a;
    while (a && *a)
        *concat++ = *a++;
    while (b && *b)
        *concat++ = *b++;
    *concat = 0;
    if (free_a && hold_a)
        free(hold_a);
    return (hold);
}