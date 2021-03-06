/*
** EPITECH PROJECT, 2020
** scan.c
** File description:
**  minishell
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include "util.h"

static char	*app(char *str, char c)
{
    char *ap;
    int	 i;
    int	 j;

    i = (j = 0);
    while (str && str[i] && ++i);
    if (!(ap = malloc(sizeof(char) * (i + (!c ? 1 : 2)))))
        return (NULL);
    while(str && j < i)
    {
        ap[j] = str[j];
        j++;
    }
    ap[j] = c;
    if (c)
        ap[j + 1] = 0;
    if (str)
        free(str);
    return (ap);
}

char *scan_line(const int file)
{
    char *str;
    char buffer[1];
    int	error;

    str = NULL;
    while ((error = read(file, buffer, 1)))
    {
        if (buffer[0] == '\n')
            return (str ? str : app(NULL, 0));
        else if (error == -1 || !(str = app(str, buffer[0])))
            break;
    }
    if (error && str)
        free(str);
    return (error ? NULL : str);
}
